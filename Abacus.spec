%{!?python_sitelib: %define python_sitelib %(%{__python} -c "from distutils.sysconfig import get_python_lib; print get_python_lib()")}
%{!?python_sitearch: %define python_sitearch %(%{__python} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(1)")}
%define mod_path ibus-@PACKAGE_VERSION_MAJOR@.@PACKAGE_VERSION_MINOR@
Name:       Abacus
Version:    1.0.0.20220501
Release:    1%{?dist}
Summary:    IBus template project
License:    GPLv2+
Group:      System Environment/Libraries
URL:        http://code.google.com/p/ibus/
Source0:    http://ibus.googlecode.com/files/%{name}-%{version}.tar.gz

BuildRoot:  %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
BuildRequires:  gettext-devel
BuildRequires:  python

Requires:   ibus
Requires:   python-enchant

%description
IBus template project.

%prep
%setup -q

%build
%configure --disable-static
# make -C po update-gmo
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=${RPM_BUILD_ROOT} install

%find_lang %{name}

%clean
rm -rf $RPM_BUILD_ROOT

%files -f %{name}.lang
%defattr(-,root,root,-)
%doc AUTHORS COPYING README
# %dir %{python_sitearch}/ibus
# %{python_sitearch}/ibus/*
%dir %{_datadir}/ibus-tmpl
%{_datadir}/ibus-tmpl
%{_bindir}/ibus-engine-enchant
%{_datadir}/ibus/engine/enchant.engine

%changelog
* Wed Jun 25 2008 Peng Huang <shawn.p.huang@gmail.com> - 0.1.0-1
- The first version.
