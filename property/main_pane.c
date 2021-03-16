/* vim:set et ts=4 sts=4:
 *
 * ibus-viethoa - The Viethoa engine for IBus
 *
 * Copyright (c) 2020-2021 Duy Thai, duybthai@yahoo.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <gtk/gtk.h>

//#include <gtk-3.0/gtk/gtk.h>


GtkWidget *_left_menu = NULL;

void add_to_list(const gchar *str) {
	if(_left_menu){
		GtkListStore *store;
		GtkTreeIter iter;

		store = GTK_LIST_STORE(
				gtk_tree_view_get_model
		  		(GTK_TREE_VIEW(_left_menu))
		);

		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, 0, str, -1);
	}
}

void create_left_menu(){
  if(!_left_menu){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;
  	
	_left_menu = gtk_tree_view_new();

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(
			"List Items",
		  	renderer, 
			"text", 
			0, 
			NULL
	);

	gtk_tree_view_append_column(GTK_TREE_VIEW(_left_menu), column);

	store = gtk_list_store_new(1, G_TYPE_STRING);

	gtk_tree_view_set_model(
			GTK_TREE_VIEW(_left_menu), 
	  		GTK_TREE_MODEL(store)
	);

	// Thêm các mục vào mênu
	add_to_list("Lựa chế độ");
	add_to_list("Chế độ chữ Việt");
	add_to_list("Chế độ chữ Hoa");
	add_to_list("Chế độ chữ Mỹ");
	add_to_list("Thông tin");

	g_object_unref(store);
  }
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *paned;
  GtkWidget *window;
  //GtkWidget *image2;

  // Tạo đối tượng window
  window = gtk_application_window_new (app);
  
  // Gắng đầu đề cho window
  gtk_window_set_title (GTK_WINDOW (window), "Bộ Gõ Việthán - Bảng Chọn Lựa");

  // Đặt kích cở cho window
  gtk_window_set_default_size (GTK_WINDOW (window), 722, 422);

  // Tạo đối tượng pane
  paned = gtk_paned_new (GTK_ORIENTATION_HORIZONTAL);

  // Tạo cây mênu
  create_left_menu(); 
  //image1 = gtk_image_new_from_file ("gnome-image.png");
  //image2 = gtk_image_new_from_file ("tux.png");

  if(_left_menu){
  	gtk_paned_add1 (GTK_PANED (paned), _left_menu);
  }
  //gtk_paned_add2 (GTK_PANED (paned), image2);
  
  // Gắng đối tượng pane vào đối tượng window
  gtk_container_add (GTK_CONTAINER (window), paned);

  // Hiển thị đối tượng window
  gtk_widget_show_all (window);
}

int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.viethoa", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return status;
}
