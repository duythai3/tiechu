
drop table if exists teochew;

create table if not exists teochew(
    _id integer primary key autoincrement,
    _teochew text not null default '',
    _char text not null default '',
    _tc_1 integer default 0,
    _tc_2 integer default 0,
    _tc_3 integer default 0,
    _tc_4 integer default 0,
    _tc_5 integer default 0,
    _tc_6 integer default 0,
    _tc_7 integer default 0,
    _frequency integer default 0,
    _pinyin text default null,
    _num_strokes integer default 0,
    _mark integer default 0
);

create index if not exists teochew_i_t_1 on teochew(_tc_1);
create index if not exists teochew_i_t_2 on teochew(_tc_2);
create index if not exists teochew_i_t_3 on teochew(_tc_3);
create index if not exists teochew_i_t_4 on teochew(_tc_4);
create index if not exists teochew_i_t_5 on teochew(_tc_5);
create index if not exists teochew_i_t_6 on teochew(_tc_6);
create index if not exists teochew_i_t_7 on teochew(_tc_7);

create index if not exists teochew_i_c on teochew(_char);
create index if not exists teochew_i_f on teochew(_frequency);
create index if not exists teochew_i_n on teochew(_num_strokes);
create index if not exists teochew_i_m on teochew(_mark);

insert into teochew (_teochew, _char, _pinyin, _num_strokes, _mark) values
('ieu1','一','yī',1,0),
a1 Details
('a1', '丫
('a1', '亚
('a1', '桠
('a1', '氩
('a1', '锕
('a1', '阿
('a1', '鸦
a2 Details
('a2', '拗
a3 Details
('a3', '亚
('a3', '垭
('a3', '娅
('a3', '詏
a7 Details
('a7', '啊

ab4 Details
('ab4', '呷
('ab4', '押
('ab4', '狎
('ab4', '腌
ab8 Details
('ab8', '匣
('ab8', '盒



ag4 Details
('ag4', '恶
('ag4', '抑
('ag4', '挜
('ag4', '揠
('ag4', '沃
('ag4', '轧



ah4 Details
('ah4', '呷
('ah4', '押
('ah4', '鸭



ai1 Details
('ai1', '哀
('ai1', '哎
('ai1', '唉
('ai1', '嗳
('ai1', '埃
('ai1', '娭
('ai1', '挨
('ai1', '锿
ai2 Details
('ai2', '叆
('ai2', '欸
('ai2', '蔼
('ai2', '霭
('ai2', '靉
ai3 Details
('ai3', '嗳
ai5 Details
('ai5', '嫒
ai7 Details
('ai7', '哎
('ai7', '嗳



ain3 Details
('ain3', '嫒
('ain3', '暧
('ain3', '欲
('ain3', '爱
('ain3', '瑷
('ain3', '艾



am1 Details
('am1', '广
('am1', '庵
('am1', '盦
('am1', '谙
('am1', '鞥
('am1', '鹌
am2 Details
('am2', '埯
('am2', '饮
am3 Details
('am3', '揞
('am3', '暗
('am3', '黯
am6 Details
('am6', '唵
('am6', '颔



an1 Details
('an1', '揞
an6 Details
('an6', '嗳
an7 Details
('an7', '馅


ang1 Details
('ang1', '安
('ang1', '桉
('ang1', '氨
('ang1', '翁
('ang1', '肮
('ang1', '胺
('ang1', '铵
ang3 Details
('ang3', '宴
('ang3', '按
('ang3', '晏
('ang3', '案
('ang3', '瓮
('ang3', '盎
('ang3', '罋
('ang3', '讌
('ang3', '鼹
ang5 Details
('ang5', '洪
('ang5', '红



ao1 Details
('ao1', '凹
('ao1', '区
('ao1', '坳
('ao1', '欧
('ao1', '殴
('ao1', '沤
('ao1', '瓯
('ao1', '窅
('ao1', '讴
('ao1', '鏖
('ao1', '鸥
ao2 Details
('ao2', '呕
('ao2', '垇
('ao2', '媪
('ao2', '拗
('ao2', '殴
('ao2', '靿
ao3 Details
('ao3', '岙
('ao3', '怄
('ao3', '懊
('ao3', '沤
ao5 Details
('ao5', '喉
ao6 Details
('ao6', '后
('ao6', '後


aon1 Details
('aon1', '眑


ba1 Details
('ba1', '叭
('ba1', '吧
('ba1', '岜
('ba1', '巴
('ba1', '扒
('ba1', '爸
('ba1', '疤
('ba1', '笆
('ba1', '粑
('ba1', '芭
('ba1', '葩
('ba1', '豝
('ba1', '钯
ba2 Details
('ba2', '把
('ba2', '靶
('ba2', '饱
ba3 Details
('ba3', '坝
('ba3', '豹
('ba3', '趵
('ba3', '霸
ba5 Details
('ba5', '叭
('ba5', '爸
ba6 Details
('ba6', '罢



bag4 Details
('bag4', '亳
('bag4', '八
('bag4', '別
('bag4', '别
('bag4', '剥
('bag4', '北
('bag4', '幅
('bag4', '捌
('bag4', '腹
('bag4', '膊
('bag4', '蝮
('bag4', '辐
bag8 Details
('bag8', '別
('bag8', '别
('bag8', '缚



bai2 Details
('bai2', '捭
('bai2', '摆
bai3 Details
('bai3', '拜
bai5 Details
('bai5', '俳
('bai5', '徘
('bai5', '排
('bai5', '棑
('bai5', '牌
('bai5', '簰
bai7 Details
('bai7', '呗
('bai7', '败



bang1 Details
('bang1', '嘣
('bang1', '崩
('bang1', '帮
('bang1', '彭
('bang1', '攽
('bang1', '斑
('bang1', '方
('bang1', '枋
('bang1', '枫
('bang1', '梆
('bang1', '浜
('bang1', '班
('bang1', '瘢
('bang1', '癍
('bang1', '祊
('bang1', '绷
('bang1', '肪
('bang1', '蹦
('bang1', '邦
('bang1', '颁
bang2 Details
('bang2', '坂
('bang2', '扳
('bang2', '板
('bang2', '榜
('bang2', '版
('bang2', '琫
('bang2', '绑
('bang2', '耪
('bang2', '膀
('bang2', '舨
('bang2', '镚
('bang2', '髈
bang3 Details
('bang3', '扮
('bang3', '放
('bang3', '柈
bang5 Details
('bang5', '冯
('bang5', '房
bang6 Details
('bang6', '棒
('bang6', '稖
('bang6', '谤
bang7 Details
('bang7', '办



bao1 Details
('bao1', '包
('bao1', '孢
('bao1', '胞
('bao1', '苞
('bao1', '龅
bao2 Details
('bao2', '保
('bao2', '堡
('bao2', '緥
('bao2', '葆
('bao2', '褓
('bao2', '鸨
bao6 Details
('bao6', '暴
('bao6', '瀑
('bao6', '爆
('bao6', '鲍


bi1 Details
('bi1', '卑
('bi1', '埤
('bi1', '庳
('bi1', '悲
('bi1', '椑
('bi1', '砒
('bi1', '碑
('bi1', '蓖
('bi1', '蜱
('bi1', '裨
('bi1', '郫
('bi1', '陂
bi2 Details
('bi2', '仳
('bi2', '俾
('bi2', '妣
('bi2', '彼
('bi2', '比
('bi2', '毗
('bi2', '沘
('bi2', '狴
('bi2', '畀
('bi2', '秕
('bi2', '稗
('bi2', '粃
('bi2', '粺
('bi2', '髀
bi3 Details
('bi3', '匕
('bi3', '庇
('bi3', '毖
('bi3', '泌
('bi3', '痹
('bi3', '秘
('bi3', '箅
('bi3', '篦
('bi3', '背
('bi3', '臂
('bi3', '诐
('bi3', '贲
('bi3', '费
('bi3', '辔
('bi3', '髀
bi5 Details
('bi5', '啤
('bi5', '枇
('bi5', '琵
('bi5', '脾
('bi5', '裨
bi6 Details
('bi6', '备
('bi6', '婢
('bi6', '币
('bi6', '惫
('bi6', '敝
('bi6', '毙
('bi6', '被
('bi6', '闭
('bi6', '陛
('bi6', '鞁
('bi6', '鞴
('bi6', '韛
bi7 Details
('bi7', '弊
('bi7', '蔽
('bi7', '避


biah4 Details
('biah4', '壁
('biah4', '璧



bian1 Details
('bian1', '兵
('bian1', '冰
bian2 Details
('bian2', '丙
('bian2', '邴
('bian2', '饼
bian3 Details
('bian3', '拚


big4 Details
('big4', '必
('big4', '滗
('big4', '珌
('big4', '笔
('big4', '苾
('big4', '觱
('big4', '邲
('big4', '铋
big8 Details
('big8', '弼
('big8', '毕
('big8', '瘪
('big8', '筚
('big8', '跸


bih4 Details
('bih4', '憋
('bih4', '鳖


bin1 Details
('bin1', '辫
('bin1', '边
('bin1', '鞭
bin2 Details
('bin2', '扁
bin3 Details
('bin3', '变
bin6 Details
('bin6', '辫


bing1 Details
('bing1', '乒
('bing1', '傧
('bing1', '宾
('bing1', '彬
('bing1', '斌
('bing1', '槟
('bing1', '浜
('bing1', '滨
('bing1', '缤
('bing1', '豳
('bing1', '邠
('bing1', '镔
bing2 Details
('bing2', '匾
('bing2', '品
('bing2', '屏
('bing2', '摒
('bing2', '榀
('bing2', '禀
bing3 Details
('bing3', '嫔
('bing3', '摈
('bing3', '殡
('bing3', '篦
('bing3', '膑
('bing3', '遍
('bing3', '髌
('bing3', '鬓
bing5 Details
('bing5', '平


biu1 Details
('biu1', '彪


biê1 Details
('biê1', '标
('biê1', '表
('biê1', '镖
('biê1', '镳
('biê1', '骉
biê2 Details
('biê2', '表
biê3 Details
('biê3', '漂
('biê3', '裱



biêg8 Details
('biêg8', '別
('biêg8', '别
('biêg8', '蹩


biêng1 Details
('biêng1', '揙
('biêng1', '笾
('biêng1', '边
('biêng1', '鞭
('biêng1', '鳊
biêng2 Details
('biêng2', '匾
('biêng2', '扁
('biêng2', '碥
('biêng2', '藊
('biêng2', '褊
('biêng2', '贬
biêng3 Details
('biêng3', '变
('biêng3', '遍
biêng6 Details
('biêng6', '便
('biêng6', '卞
('biêng6', '弁
('biêng6', '忭
('biêng6', '抃
('biêng6', '汴
('biêng6', '瓣
('biêng6', '窆
('biêng6', '覍
('biêng6', '辨
('biêng6', '辩
('biêng6', '釆



bo1 Details
('bo1', '坡
('bo1', '嶓
('bo1', '波
('bo1', '玻
('bo1', '菠
bo2 Details
('bo2', '保
('bo2', '宝
('bo2', '寳
bo3 Details
('bo3', '报
bo5 Details
('bo5', '婆
('bo5', '薄
('bo5', '蟆
bo7 Details
('bo7', '啵



bog4 Details
('bog4', '卜
bog8 Details
('bog8', '仆
('bog8', '卜



boh4 Details
('boh4', '驳
boh8 Details
('boh8', '泊
('boh8', '礴
('boh8', '箔
('boh8', '舶
('boh8', '薄
('boh8', '铂
('boh8', '魄



boih4 Details
('boih4', '八
('boih4', '捌
boih8 Details
('boih8', '拔



boin1 Details
('boin1', '斑
('boin1', '瘢
('boin1', '癍
boin2 Details
('boin2', '反
('boin2', '板
('boin2', '版
boin5 Details
('boin5', '爿
('boin5', '畔


bong5 Details
('bong5', '乓
('bong5', '泵
bong6 Details
('bong6', '并
bong7 Details
('bong7', '磅
('bong7', '镑


bou1 Details
('bou1', '埔
('bou1', '埠
('bou1', '夫
('bou1', '餔
bou2 Details
('bou2', '斧
('bou2', '脯
('bou2', '补
bou3 Details
('bou3', '傅
('bou3', '布
bou5 Details
('bou5', '醭
bou6 Details
('bou6', '部
bou7 Details
('bou7', '哺
('bou7', '步


bu1 Details
('bu1', '晡
('bu1', '逋
('bu1', '餔
bu3 Details
('bu3', '富
('bu3', '布
('bu3', '怖
('bu3', '背
bu5 Details
('bu5', '煲
('bu5', '瓠
('bu5', '脬
bu6 Details
('bu6', '哺
('bu6', '妇
('bu6', '捕
('bu6', '胕
bu7 Details
('bu7', '伏



bua3 Details
('bua3', '播
('bua3', '簸



buah4 Details
('buah4', '钵
buah8 Details
('buah8', '拔
('buah8', '跋



buan1 Details
('buan1', '搬
('buan1', '般
buan3 Details
('buan3', '半
buan5 Details
('buan5', '盘
('buan5', '蹯


bug4 Details
('bug4', '不
('bug4', '吥
('bug4', '钚


bui1 Details
('bui1', '卑
('bui1', '坏
('bui1', '埤
('bui1', '悲
('bui1', '阫
bui3 Details
('bui3', '痱
bui5 Details
('bui5', '淝
('bui5', '肥
bui7 Details
('bui7', '吠



bung1 Details
('bung1', '分
('bung1', '奔
('bung1', '方
('bung1', '犇
bung2 Details
('bung2', '本
('bung2', '笨
('bung2', '苯
bung3 Details
('bung3', '夯
('bung3', '畚
('bung3', '笨
('bung3', '粪
bung6 Details
('bung6', '笨
bung7 Details
('bung7', '饭



buê1 Details
('buê1', '杯
('buê1', '桮
('buê1', '飞
buê3 Details
('buê3', '背
('buê3', '褙
('buê3', '贝
('buê3', '辈
buê5 Details
('buê5', '培
('buê5', '赔
('buê5', '锫
('buê5', '陪
buê6 Details
('buê6', '佩
('buê6', '倍
('buê6', '悖
('buê6', '掊
('buê6', '狈
('buê6', '珮
('buê6', '碚
('buê6', '蓓
('buê6', '贝
('buê6', '邶
('buê6', '钡
buê7 Details
('buê7', '焙


buêg8 Details
('buêg8', '勃
('buêg8', '孛
('buêg8', '拔
('buêg8', '桲
('buêg8', '渤
('buêg8', '脖
('buêg8', '荸
('buêg8', '跋
('buêg8', '钹
('buêg8', '饽
('buêg8', '魃
('buêg8', '鲅
('buêg8', '鹁
('buêg8', '鼥


buêng6 Details
('buêng6', '叛



bê2 Details
('bê2', '把
bê5 Details
('bê5', '扒
('bê5', '掱
('bê5', '杷
('bê5', '爬
('bê5', '琶
('bê5', '筢
('bê5', '耙
('bê5', '蟛
bê6 Details
('bê6', '父
bê7 Details
('bê7', '呗



bêg4 Details
('bêg4', '伯
('bêg4', '偪
('bêg4', '愊
('bêg4', '愎
('bêg4', '柏
('bêg4', '煏
('bêg4', '皕
('bêg4', '薄
('bêg4', '迫
('bêg4', '逼



bêh4 Details
('bêh4', '伯
('bêh4', '佰
('bêh4', '掰
('bêh4', '柏
('bêh4', '栢
('bêh4', '檗
('bêh4', '百
bêh8 Details
('bêh8', '帛
('bêh8', '白
('bêh8', '铂
('bêh8', '鲌



bên3 Details
('bên3', '把
('bên3', '柄
bên5 Details
('bên5', '平
('bên5', '棚
bên7 Details
('bên7', '病



bêng2 Details
('bêng2', '炳
('bêng2', '秉
('bêng2', '邴
bêng5 Details
('bêng5', '迸
bêng6 Details
('bêng6', '并
('bêng6', '栟
('bêng6', '甏
('bêng6', '胼
('bêng6', '骈


bha3 Details
('bha3', '䶕


bhag8 Details
('bhag8', '墨
('bhag8', '木



bhai5 Details
('bhai5', '嵋
('bhai5', '楣
('bhai5', '湄
('bhai5', '猸
('bhai5', '眉
('bhai5', '郿
('bhai5', '镅
('bhai5', '鹛


bhao2 Details
('bhao2', '卯
('bhao2', '夘
('bhao2', '峁
('bhao2', '昴
('bhao2', '泖
('bhao2', '铆


bhi2 Details
('bhi2', '米
('bhi2', '脒
bhi7 Details
('bhi7', '味
('bhi7', '未
('bhi7', '沕



bhig8 Details
('bhig8', '蜜



bhih4 Details
('bhih4', '瘪
bhih8 Details
('bhih8', '篾



bhiê5 Details
('bhiê5', '描
('bhiê5', '瞄
bhiê7 Details
('bhiê7', '庙



bho2 Details
('bho2', '拇
('bho2', '母
bho5 Details
('bho5', '亡
('bho5', '呒
('bho5', '无
('bho5', '毋
('bho5', '没
bho7 Details
('bho7', '帽
('bho7', '磨



bhoi2 Details
('bhoi2', '买
('bhoi2', '荬
bhoi6 Details
('bhoi6', '𠀾
bhoi7 Details
('bhoi7', '卖



bhou2 Details
('bhou2', '亩
('bhou2', '母
('bhou2', '牡
('bhou2', '𡚸
bhou5 Details
('bhou5', '模
bhou7 Details
('bhou7', '戊



bhu2 Details
('bhu2', '侮
('bhu2', '妩
('bhu2', '怃
('bhu2', '抚
('bhu2', '拊
('bhu2', '武
('bhu2', '舞
('bhu2', '鹉
bhu5 Details
('bhu5', '巫
('bhu5', '庑
('bhu5', '无
('bhu5', '芜
('bhu5', '诬
bhu6 Details
('bhu6', '务
('bhu6', '婺
('bhu6', '骛
('bhu6', '鹜
bhu7 Details
('bhu7', '雾



bhua5 Details
('bhua5', '磨



bhuah4 Details
('bhuah4', '抹
('bhuah4', '拨
bhuah8 Details
('bhuah8', '末
('bhuah8', '沫
('bhuah8', '钹



bhuang2 Details
('bhuang2', '妄
('bhuang2', '惘
('bhuang2', '罔
('bhuang2', '辋
('bhuang2', '魍
bhuang5 Details
('bhuang5', '亡
('bhuang5', '忘
bhuang6 Details
('bhuang6', '望
('bhuang6', '朢


bhug4 Details
('bhug4', '勿
('bhug4', '吻
('bhug4', '肳



bhung1 Details
('bhung1', '炆
('bhung1', '焖
('bhung1', '蚊
bhung2 Details
('bhung2', '抆
bhung5 Details
('bhung5', '文
('bhung5', '旻
('bhung5', '玫
('bhung5', '紊
('bhung5', '纹
('bhung5', '阌
('bhung5', '雯
bhung6 Details
('bhung6', '闻
bhung7 Details
('bhung7', '懑
('bhung7', '汶
('bhung7', '闷



bhuê2 Details
('bhuê2', '尾
('bhuê2', '美
bhuê5 Details
('bhuê5', '媒
('bhuê5', '枚
('bhuê5', '梅
('bhuê5', '楳
('bhuê5', '煤
('bhuê5', '脢
('bhuê5', '莓
('bhuê5', '酶
('bhuê5', '霉
bhuê7 Details
('bhuê7', '未


bhuêh8 Details
('bhuêh8', '袜
('bhuêh8', '韈



bhuêng2 Details
('bhuêng2', '墁
('bhuêng2', '嫚
('bhuêng2', '熳
('bhuêng2', '缦
bhuêng6 Details
('bhuêng6', '幔
('bhuêng6', '慢
('bhuêng6', '曼
('bhuêng6', '漫
('bhuêng6', '蔓
('bhuêng6', '谩
('bhuêng6', '镘
('bhuêng6', '馒
('bhuêng6', '鬘
bhuêng7 Details
('bhuêng7', '万
('bhuêng7', '萬



bhê2 Details
('bhê2', '码
('bhê2', '马


bhêh8 Details
('bhêh8', '麦


ca1 Details
('ca1', '喳
('ca1', '岔
('ca1', '嵯
('ca1', '差
('ca1', '搓
('ca1', '蹉
ca2 Details
('ca2', '炒
ca3 Details
('ca3', '咤
('ca3', '姹
('ca3', '礤
('ca3', '诧
('ca3', '蹅
ca5 Details
('ca5', '垞
('ca5', '搽
('ca5', '柴
('ca5', '茬



cag4 Details
('cag4', '嚓
('cag4', '察
('cag4', '擦
('cag4', '漆
('cag4', '膝
('cag4', '詧
('cag4', '错
('cag4', '镲
cag8 Details
('cag8', '凿
('cag8', '贼


cah4 Details
('cah4', '挿
('cah4', '插
('cah4', '歃
('cah4', '锸



cai1 Details
('cai1', '猜
cai2 Details
('cai2', '倸
('cai2', '彩
('cai2', '睬
('cai2', '跴
('cai2', '踩
('cai2', '采
cai3 Details
('cai3', '菜
cai5 Details
('cai5', '才
('cai5', '材
('cai5', '裁
('cai5', '豺
('cai5', '财


cam1 Details
('cam1', '参
('cam1', '參
('cam1', '掺
('cam1', '碜
('cam1', '骖
cam2 Details
('cam2', '惨
cam3 Details
('cam3', '渗
cam5 Details
('cam5', '岑
('cam5', '巉
('cam5', '惭
('cam5', '搀
('cam5', '谗
('cam5', '镵
('cam5', '馋



cang1 Details
('cang1', '仓
('cang1', '伧
('cang1', '孱
('cang1', '戗
('cang1', '沧
('cang1', '玱
('cang1', '苍
('cang1', '葱
('cang1', '跄
('cang1', '锵
('cang1', '餐
('cang1', '鸧
cang2 Details
('cang2', '刬
('cang2', '铲
('cang2', '骣
cang3 Details
('cang3', '创
('cang3', '怆
('cang3', '灿
('cang3', '炝
('cang3', '璨
('cang3', '粲
cang5 Details
('cang5', '残
('cang5', '潺
('cang5', '田
('cang5', '缠
('cang5', '臧
('cang5', '藏
cang6 Details
('cang6', '羼



cao1 Details
('cao1', '剿
('cao1', '勦
('cao1', '吵
('cao1', '抄
('cao1', '撡
('cao1', '操
('cao1', '耖
('cao1', '钞
cao2 Details
('cao2', '艸
('cao2', '草
cao3 Details
('cao3', '喿
('cao3', '噪
('cao3', '慥
('cao3', '操
('cao3', '澡
('cao3', '燥
('cao3', '臊
('cao3', '臭
('cao3', '藻
('cao3', '躁
('cao3', '鱢
cao5 Details
('cao5', '嘈
('cao5', '巢
('cao5', '曹
('cao5', '漕
('cao5', '缫
('cao5', '艚
('cao5', '螬


ce1 Details
('ce1', '摅
('ce1', '蛆
('ce1', '觑
('ce1', '跐
ce2 Details
('ce2', '佌
('ce2', '此
('ce2', '跐
('ce2', '鼠
ce3 Details
('ce3', '佽
('ce3', '次
('ce3', '觑
ce5 Details
('ce5', '徐
('ce5', '慈
('ce5', '瓷
('ce5', '甆
('ce5', '疵
('ce5', '磁
('ce5', '糍
('ce5', '茨
('ce5', '訾
('ce5', '雌
('ce5', '頾
('ce5', '餈
('ce5', '髭
('ce5', '鹚


ceng1 Details
('ceng1', '仓
('ceng1', '伧
('ceng1', '村
('ceng1', '疮
('ceng1', '穿
('ceng1', '舱
('ceng1', '邨
ceng3 Details
('ceng3', '刺
ceng5 Details
('ceng5', '床
('ceng5', '牀



ci1 Details
('ci1', '凄
('ci1', '哧
('ci1', '嗤
('ci1', '妻
('ci1', '媸
('ci1', '差
('ci1', '恓
('ci1', '栖
('ci1', '痴
('ci1', '癡
('ci1', '眵
('ci1', '笞
('ci1', '萋
('ci1', '蚩
('ci1', '郪
('ci1', '鳃
('ci1', '鸱
ci2 Details
('ci2', '侈
('ci2', '耻
('ci2', '茝
('ci2', '褫
ci3 Details
('ci3', '刺
('ci3', '弑
('ci3', '朿
('ci3', '眦
('ci3', '蛓
('ci3', '试
ci5 Details
('ci5', '墀
('ci5', '竾
('ci5', '篪
('ci5', '荠
('ci5', '蛴
('ci5', '迟
('ci5', '驰
('ci5', '齐
ci6 Details
('ci6', '市
('ci6', '铈
ci7 Details
('ci7', '饲



cia1 Details
('cia1', '奢
('cia1', '砗
('cia1', '赊
('cia1', '车
cia2 Details
('cia2', '且


ciag4 Details
('ciag4', '戳
('ciag4', '绰
('ciag4', '芍
('ciag4', '雀
('ciag4', '鹊


ciah4 Details
('ciah4', '倩
('ciah4', '赤


cian2 Details
('cian2', '请
('cian2', '趄
cian5 Details
('cian5', '伥
('cian5', '成



ciang1 Details
('ciang1', '呛
('ciang1', '娼
('ciang1', '戕
('ciang1', '斨
('ciang1', '昌
('ciang1', '猖
('ciang1', '箐
('ciang1', '菖
('ciang1', '阊
('ciang1', '鲳
ciang2 Details
('ciang2', '厂
('ciang2', '呛
('ciang2', '敞
('ciang2', '昶
('ciang2', '氅
ciang3 Details
('ciang3', '倡
('ciang3', '唱
ciang5 Details
('ciang5', '场
('ciang5', '嫱
('ciang5', '常
('ciang5', '樯
('ciang5', '爿
('ciang5', '肠
('ciang5', '苌
('ciang5', '蔷
('ciang5', '长



cib4 Details
('cib4', '戢
('cib4', '楫
('cib4', '缉
('cib4', '葺
('cib4', '蕺
('cib4', '辑



cieu2 Details
('cieu2', '俏
('cieu2', '嘲
('cieu2', '峭
('cieu2', '愀
('cieu2', '湫
('cieu2', '稍
('cieu2', '謿
('cieu2', '诮
cieu5 Details
('cieu5', '晁
('cieu5', '朝
('cieu5', '瞧


cig4 Details
('cig4', '七
('cig4', '拭
('cig4', '柒



cih8 Details
('cih8', '彳
('cih8', '蠘



cim1 Details
('cim1', '棽
('cim1', '深
cim2 Details
('cim2', '寝
('cim2', '梫
cim3 Details
('cim3', '吢
('cim3', '吣
('cim3', '沁
cim5 Details
('cim5', '侵
('cim5', '寻
('cim5', '浔
('cim5', '荨
('cim5', '锓
('cim5', '骎
('cim5', '鲟
cim6 Details
('cim6', '蕈



cin1 Details
('cin1', '鲜
cin2 Details
('cin2', '齿
cin5 Details
('cin5', '寻



cing1 Details
('cing1', '亲
cing3 Details
('cing3', '凊
('cing3', '榇
('cing3', '秤
('cing3', '称
('cing3', '龀
cing5 Details
('cing5', '溱
('cing5', '秦
('cing5', '臣
('cing5', '螓
('cing5', '陈



ciu1 Details
('ciu1', '初
('ciu1', '啾
('ciu1', '揪
('ciu1', '揫
('ciu1', '楸
('ciu1', '湫
('ciu1', '瞅
('ciu1', '矁
('ciu1', '秋
('ciu1', '秌
('ciu1', '萩
('ciu1', '鞧
('ciu1', '须
('ciu1', '鬏
('ciu1', '鳅
('ciu1', '鹙
ciu2 Details
('ciu2', '丑
('ciu2', '手
ciu3 Details
('ciu3', '漱
('ciu3', '潄
ciu5 Details
('ciu5', '仇
('ciu5', '售
('ciu5', '囚
('ciu5', '揂
('ciu5', '詶
('ciu5', '酬
('ciu5', '雠
ciu7 Details
('ciu7', '树



ciê3 Details
('ciê3', '唱
('ciê3', '笑


ciêg4 Details
('ciêg4', '切
('ciêg4', '沏
('ciêg4', '窃



ciêh4 Details
('ciêh4', '尺
('ciêh4', '淖
ciêh8 Details
('ciêh8', '席
('ciêh8', '蓆



ciên1 Details
('ciên1', '枪
('ciên1', '鎗
('ciên1', '鲳
ciên2 Details
('ciên2', '抢
ciên5 Details
('ciên5', '墙
('ciên5', '鲿
ciên6 Details
('ciên6', '上
('ciên6', '像
('ciên6', '橡
('ciên6', '象
ciên7 Details
('ciên7', '匠



ciêng1 Details
('ciêng1', '千
('ciêng1', '扦
('ciêng1', '纤
('ciêng1', '芊
('ciêng1', '跹
('ciêng1', '迁
('ciêng1', '钎
('ciêng1', '阡
ciêng2 Details
('ciêng2', '浅



co1 Details
('co1', '初
('co1', '搓
('co1', '臊
('co1', '鱢
co2 Details
('co2', '憷
('co2', '楚
('co2', '础
('co2', '艸
('co2', '草
co3 Details
('co3', '剉
('co3', '糙
('co3', '脞
('co3', '锉
('co3', '错
co5 Details
('co5', '挫
('co5', '痤
('co5', '矬
('co5', '磋
('co5', '鉏
('co5', '锄
('co5', '鹾



cog4 Details
('cog4', '亍
('cog4', '促
('cog4', '娖
('cog4', '戳
('cog4', '捉
('cog4', '柷
('cog4', '浞
('cog4', '焯
('cog4', '矗
('cog4', '触
('cog4', '踧
('cog4', '蹙
('cog4', '蹴
('cog4', '蹵
('cog4', '躅
('cog4', '龉


coh4 Details
('coh4', '撮
('coh4', '错
coh8 Details
('coh8', '亍


coi3 Details
('coi3', '磜
('coi3', '粞



coin1 Details
('coin1', '仟
('coin1', '千
coin2 Details
('coin2', '筅
('coin2', '箲
coin5 Details
('coin5', '蚕



cong1 Details
('cong1', '充
('cong1', '冲
('cong1', '匆
('cong1', '囱
('cong1', '忡
('cong1', '怱
('cong1', '枞
('cong1', '种
('cong1', '翀
('cong1', '聪
('cong1', '茺
('cong1', '葱
('cong1', '衷
('cong1', '骢
cong3 Details
('cong3', '冲
cong5 Details
('cong5', '从
('cong5', '崇
('cong5', '従
('cong5', '苁
('cong5', '重


cou1 Details
('cou1', '粗
('cou1', '麤
cou3 Details
('cou3', '凑
('cou3', '揍
('cou3', '腠
('cou3', '辏
('cou3', '酢
('cou3', '醋
cou5 Details
('cou5', '愁


cu1 Details
('cu1', '刍
('cu1', '樗
('cu1', '趋
('cu1', '雏
('cu1', '鲰
cu2 Details
('cu2', '取
('cu2', '处
('cu2', '娶
cu3 Details
('cu3', '厝
('cu3', '处
('cu3', '措
('cu3', '趣
cu5 Details
('cu5', '滁


cua2 Details
('cua2', '歪
cua3 Details
('cua3', '蔡
cua7 Details
('cua7', '娶



cuah4 Details
('cuah4', '敠


cuan3 Details
('cuan3', '闩


cug4 Details
('cug4', '出
('cug4', '黟



cui1 Details
('cui1', '催
('cui1', '崔
('cui1', '推
('cui1', '摧
('cui1', '璀
cui2 Details
('cui2', '惴
('cui2', '揣
('cui2', '毳
('cui2', '踹
cui3 Details
('cui3', '啐
('cui3', '喙
('cui3', '嘴
('cui3', '碎
('cui3', '粹
('cui3', '翠
('cui3', '脆
('cui3', '膵
('cui3', '觜
cui5 Details
('cui5', '膗


cung1 Details
('cung1', '伸
('cung1', '春
('cung1', '椿
('cung1', '萅
('cung1', '逡
('cung1', '鰆
cung2 Details
('cung2', '忖
('cung2', '惷
('cung2', '舛
('cung2', '蠢
cung3 Details
('cung3', '吋
('cung3', '寸
cung5 Details
('cung5', '存
('cung5', '淳
('cung5', '湻



cuê1 Details
('cuê1', '吹
('cuê1', '炊
cuê2 Details
('cuê2', '髓
cuê5 Details
('cuê5', '棰
('cuê5', '槯
('cuê5', '箠
cuê7 Details
('cuê7', '觅



cuêg4 Details
('cuêg4', '惙
('cuêg4', '拙
('cuêg4', '掇
('cuêg4', '撮
('cuêg4', '绌
('cuêg4', '缀
('cuêg4', '茁
('cuêg4', '蕞
('cuêg4', '辍
('cuêg4', '醊



cuêng1 Details
('cuêng1', '川
('cuêng1', '氚
('cuêng1', '皴
('cuêng1', '穿
('cuêng1', '镩
cuêng2 Details
('cuêng2', '喘
('cuêng2', '踳
cuêng3 Details
('cuêng3', '串
('cuêng3', '撺
('cuêng3', '窜
('cuêng3', '篡
('cuêng3', '纂
('cuêng3', '蹿
('cuêng3', '钏
('cuêng3', '闯
cuêng5 Details
('cuêng5', '佺
('cuêng5', '全
('cuêng5', '悛
('cuêng5', '拴
('cuêng5', '栓
('cuêng5', '痊
('cuêng5', '筌
('cuêng5', '荃
('cuêng5', '诠
('cuêng5', '辁
('cuêng5', '醛
('cuêng5', '铨
cuêng6 Details
('cuêng6', '圌
('cuêng6', '篅



cê1 Details
('cê1', '叉
('cê1', '尺
('cê1', '岔
('cê1', '差
('cê1', '杈
('cê1', '汊
('cê1', '衩
cê2 Details
('cê2', '扯
('cê2', '撦
cê3 Details
('cê3', '厕
('cê3', '瘥
cê5 Details
('cê5', '嵖
('cê5', '查



cêg4 Details
('cêg4', '侧
('cêg4', '僳
('cêg4', '叱
('cêg4', '嘁
('cêg4', '坼
('cêg4', '彳
('cêg4', '恻
('cêg4', '戚
('cêg4', '斥
('cêg4', '槭
('cêg4', '测
('cêg4', '玊
('cêg4', '粟
('cêg4', '


cêh4 Details
('cêh4', '册
('cêh4', '策
('cêh4', '筞


cên1 Details
('cên1', '星
('cên1', '氰
('cên1', '煋
('cên1', '生
('cên1', '腥
('cên1', '蜻
('cên1', '青
('cên1', '鲭
cên2 Details
('cên2', '醒



cêng1 Details
('cêng1', '偁
('cêng1', '圊
('cêng1', '柽
('cêng1', '清
('cêng1', '称
cêng3 Details
('cêng3', '倩
('cêng3', '称
('cêng3', '茜
('cêng3', '蒨
('cêng3', '衬
('cêng3', '铳
cêng5 Details
('cêng5', '情
('cêng5', '枨
('cêng5', '橙
('cêng5', '饧
cêng7 Details
('cêng7', '穿


da1 Details
('da1', '丈
('da1', '大
('da1', '灱
da2 Details
('da2', '打
da5 Details
('da5', '禾



dab4 Details
('dab4', '瘩
('dab4', '答


dag4 Details
('dag4', '妲
('dag4', '怛
('dag4', '笪
('dag4', '靼
('dag4', '鞑
dag8 Details
('dag8', '值
('dag8', '垯
('dag8', '度
('dag8', '毐
('dag8', '毒
('dag8', '独
('dag8', '踱
('dag8', '达
('dag8', '铎



dah4 Details
('dah4', '嗒
('dah4', '搭
('dah4', '耷
('dah4', '脦
('dah4', '褡
('dah4', '遢
dah8 Details
('dah8', '沓
('dah8', '踏
('dah8', '遝



dai1 Details
('dai1', '呆
dai2 Details
('dai2', '叇
('dai2', '歹
('dai2', '逮
dai3 Details
('dai3', '代
('dai3', '岱
('dai3', '戴
('dai3', '玳
('dai3', '膪
('dai3', '襶
('dai3', '贷
('dai3', '黛
('dai3', '黱
dai6 Details
('dai6', '大
('dai6', '怠
('dai6', '殆
('dai6', '甙
('dai6', '绐
('dai6', '轪
('dai6', '迨
('dai6', '逮
dai7 Details
('dai7', '事



dam1 Details
('dam1', '儋
('dam1', '湛
('dam1', '眈
('dam1', '耼
('dam1', '耽
('dam1', '聃
('dam1', '酖
dam2 Details
('dam2', '萏
('dam2', '黵
dam3 Details
('dam3', '髧
dam5 Details
('dam5', '㴷
dam6 Details
('dam6', '啖
('dam6', '啗
('dam6', '淡
('dam6', '赕


dan1 Details
('dan1', '担
dan2 Details
('dan2', '胆
dan3 Details
('dan3', '呾
('dan3', '担
('dan3', '石
dan6 Details
('dan6', '掷
('dan6', '氮
('dan6', '淡
('dan6', '澹



dang1 Details
('dang1', '东
('dang1', '中
('dang1', '丹
('dang1', '冬
('dang1', '坍
('dang1', '当
('dang1', '担
('dang1', '档
('dang1', '殚
('dang1', '氡
('dang1', '珰
('dang1', '箪
('dang1', '裆
('dang1', '郸
('dang1', '铛
('dang1', '鸫
dang2 Details
('dang2', '亶
('dang2', '党
('dang2', '等
('dang2', '董
('dang2', '蕫
('dang2', '谠
dang3 Details
('dang3', '冻
('dang3', '当
('dang3', '挡
('dang3', '旦
('dang3', '档
('dang3', '蛋
('dang3', '诞
dang5 Details
('dang5', '仝
('dang5', '同
('dang5', '曈
('dang5', '童
('dang5', '筒
('dang5', '筩
('dang5', '铜
('dang5', '陈
dang6 Details
('dang6', '但
('dang6', '凼
('dang6', '动
('dang6', '宕
('dang6', '惮
('dang6', '掸
('dang6', '瘅
('dang6', '砀
('dang6', '筒
('dang6', '筩
('dang6', '茼
('dang6', '荡
('dang6', '菪
('dang6', '重
dang7 Details
('dang7', '垌
('dang7', '峒
('dang7', '洞
('dang7', '硐



dao1 Details
('dao1', '兜
('dao1', '兠
('dao1', '叨
('dao1', '唗
('dao1', '忉
('dao1', '氘
('dao1', '篼
('dao1', '蔸
('dao1', '逗
dao2 Details
('dao2', '倒
('dao2', '岛
('dao2', '找
('dao2', '抖
('dao2', '捣
('dao2', '捯
('dao2', '斗
('dao2', '枓
('dao2', '祷
('dao2', '蚪
('dao2', '钭
('dao2', '阧
('dao2', '陡
dao3 Details
('dao3', '斗
('dao3', '昼
dao5 Details
('dao5', '投
('dao5', '骰
dao6 Details
('dao6', '导
('dao6', '盗
('dao6', '稻
('dao6', '蹈
('dao6', '道
dao7 Details
('dao7', '痘
('dao7', '读
('dao7', '豆



de1 Details
('de1', '猪
de5 Details
('de5', '锄
('de5', '除
de7 Details
('de7', '筯
('de7', '箸



deng1 Details
('deng1', '当
deng2 Details
('deng2', '转
deng3 Details
('deng3', '当
('deng3', '挡
('deng3', '顿
deng5 Details
('deng5', '唐
('deng5', '堂
('deng5', '塘
('deng5', '肠
('deng5', '长
deng6 Details
('deng6', '丈
('deng6', '断
deng7 Details
('deng7', '传
('deng7', '塅
('deng7', '椴
('deng7', '段
('deng7', '缎



di1 Details
('di1', '低
('di1', '底
('di1', '椥
('di1', '氐
('di1', '的
('di1', '知
('di1', '祗
('di1', '羝
('di1', '胝
('di1', '蜘
('di1', '踟
('di1', '鞮
di2 Details
('di2', '坻
('di2', '底
('di2', '徴
('di2', '徵
('di2', '抵
('di2', '柢
('di2', '氐
('di2', '砥
('di2', '诋
('di2', '邸
('di2', '骶
di3 Details
('di3', '帝
('di3', '戴
('di3', '智
('di3', '知
('di3', '碲
('di3', '置
('di3', '致
('di3', '踬
di5 Details
('di5', '持
('di5', '池
('di5', '治
('di5', '递
di6 Details
('di6', '娣
('di6', '弟
('di6', '彘
('di6', '悌
('di6', '棣
('di6', '滍
('di6', '豸
('di6', '逮
('di6', '锑
('di6', '隶
('di6', '雉
('di6', '髢
di7 Details
('di7', '地
('di7', '底
('di7', '治
('di7', '的


dia1 Details
('dia1', '爷
('dia1', '爹
dia6 Details
('dia6', '嗲



diah4 Details
('diah4', '嫡
('diah4', '摘
('diah4', '谪
diah8 Details
('diah8', '籴


dian1 Details
('dian1', '揨
dian2 Details
('dian2', '鼎
dian5 Details
('dian5', '呈
('dian5', '埕
('dian5', '庭
dian6 Details
('dian6', '锭
dian7 Details
('dian7', '定


dig4 Details
('dig4', '得
('dig4', '锝
dig8 Details
('dig8', '直


dih4 Details
('dih4', '啇
('dih4', '啑
('dih4', '喋
('dih4', '渧
('dih4', '滴
('dih4', '蒂
('dih4', '蔕
dih8 Details
('dih8', '碟



dim1 Details
('dim1', '琛
('dim1', '郴
('dim1', '酖
('dim1', '鸩
dim3 Details
('dim3', '揕
dim5 Details
('dim5', '沈
('dim5', '沉
dim6 Details
('dim6', '朕


din5 Details
('din5', '缠
din6 Details
('din6', '㶘
('din6', '涨


ding1 Details
('ding1', '颠
ding2 Details
('ding2', '振
ding3 Details
('ding3', '鎭
('ding3', '镇
ding5 Details
('ding5', '尘
('ding5', '藤
('ding5', '陈
('ding5', '鰧
ding6 Details
('ding6', '纼
ding7 Details
('ding7', '阵



diu1 Details
('diu1', '丢
('diu1', '侜
('diu1', '铥
diu2 Details
('diu2', '伫
('diu2', '杼
('diu2', '肘
('diu2', '胄
('diu2', '贮
diu5 Details
('diu5', '绸
diu6 Details
('diu6', '咮
('diu6', '宙
('diu6', '昼
('diu6', '稻
('diu6', '籀
('diu6', '纣
('diu6', '纻
('diu6', '苎
('diu6', '荮
('diu6', '酎
diu7 Details
('diu7', '住



diê5 Details
('diê5', '潮



diêb8 Details
('diêb8', '啑
('diêb8', '喋
('diêb8', '堞
('diêb8', '揲
('diêb8', '牒
('diêb8', '蜨
('diêb8', '蝶
('diêb8', '谍
('diêb8', '蹀
('diêb8', '鲽


diêg4 Details
('diêg4', '厔
('diêg4', '哲
('diêg4', '喆
('diêg4', '垤
('diêg4', '帙
('diêg4', '抶
('diêg4', '昳
('diêg4', '桎
('diêg4', '瓞
('diêg4', '秩
('diêg4', '窒
('diêg4', '绖
('diêg4', '耊
('diêg4', '膣
('diêg4', '蛭
('diêg4', '蜇
('diêg4', '袟
('diêg4', '跌
('diêg4', '轾
('diêg4', '辄
('diêg4', '迭
('diêg4', '郅
diêg8 Details
('diêg8', '侄
('diêg8', '姪



diêh4 Details
('diêh4', '着
('diêh4', '著
('diêh4', '鐯
diêh8 Details
('diêh8', '着


diên1 Details
('diên1', '张
diên2 Details
('diên2', '长
diên3 Details
('diên3', '帐
('diên3', '胀
('diên3', '账
('diên3', '钓
diên5 Details
('diên5', '场
diên6 Details
('diên6', '丈
('diên6', '赵


diêng1 Details
('diêng1', '巅
('diêng1', '巓
('diêng1', '滇
('diêng1', '珍
('diêng1', '珎
('diêng1', '癫
('diêng1', '颠
diêng2 Details
('diêng2', '典
('diêng2', '冁
('diêng2', '展
('diêng2', '抻
('diêng2', '捵
('diêng2', '搌
('diêng2', '碘
('diêng2', '碾
('diêng2', '腆
('diêng2', '觍
('diêng2', '蹍
('diêng2', '辗
diêng6 Details
('diêng6', '垫
('diêng6', '奠
('diêng6', '殿
('diêng6', '淀
('diêng6', '电
('diêng6', '甸
('diêng6', '癜


do1 Details
('do1', '刀
('do1', '哆
('do1', '多
('do1', '鱽
do2 Details
('do2', '倒
('do2', '朵
('do2', '短
do3 Details
('do3', '倒
('do3', '地
('do3', '戴
do5 Details
('do5', '刴
('do5', '剁
('do5', '垛
('do5', '垜
('do5', '埵
('do5', '朵
('do5', '朶
('do5', '淘
('do5', '躱
('do5', '躲
('do5', '逃
do6 Details
('do6', '在
('do6', '跥
('do6', '跺
do7 Details
('do7', '代
('do7', '埭
('do7', '袋



dog4 Details
('dog4', '斫
('dog4', '斲
('dog4', '督
('dog4', '筑
('dog4', '诼
dog8 Details
('dog8', '咑
('dog8', '椟
('dog8', '毒
('dog8', '涿
('dog8', '渎
('dog8', '牍
('dog8', '犊
('dog8', '独
('dog8', '瘃
('dog8', '碡
('dog8', '笃
('dog8', '觌
('dog8', '逐
('dog8', '髑
('dog8', '黩



doh4 Details
('doh4', '倬
('doh4', '卓
('doh4', '厾
('doh4', '啄
('doh4', '敠
('doh4', '桌
('doh4', '棹
('doh4', '椓
('doh4', '櫂
('doh4', '焯
('doh4', '琢
('doh4', '诼
('doh4', '踔
('doh4', '逴
doh8 Details
('doh8', '剟
('doh8', '夺
('doh8', '择
('doh8', '掇
('doh8', '着


doi1 Details
('doi1', '堤
('doi1', '隄
doi2 Details
('doi2', '底
('doi2', '抵
doi5 Details
('doi5', '蹄
('doi5', '蹏
('doi5', '题


doin6 Details
('doin6', '佃
('doin6', '第
doin7 Details
('doin7', '橂
('doin7', '殿
('doin7', '癜
('doin7', '靛
('doin7', '𠕇


dong1 Details
('dong1', '东
('dong1', '中
('dong1', '冬
('dong1', '咚
('dong1', '岽
('dong1', '忠
dong2 Details
('dong2', '懂
('dong2', '董
('dong2', '蕫
dong3 Details
('dong3', '中
('dong3', '冻
('dong3', '栋
('dong3', '疼
('dong3', '胨
dong5 Details
('dong5', '僮
('dong5', '幢
dong6 Details
('dong6', '仲
('dong6', '动
('dong6', '胴
('dong6', '重


dou1 Details
('dou1', '嘟
('dou1', '都
dou2 Details
('dou2', '肚
dou3 Details
('dou3', '斗
dou5 Details
('dou5', '厨
('dou5', '图
('dou5', '屠
dou6 Details
('dou6', '土
('dou6', '杜
('dou6', '窦
('dou6', '肚
('dou6', '脰
('dou6', '芏
('dou6', '饾
dou7 Details
('dou7', '度
('dou7', '渡
('dou7', '镀


du1 Details
('du1', '嘟
('du1', '堆
('du1', '株
('du1', '蛛
('du1', '诛
du2 Details
('du2', '堵
('du2', '楮
('du2', '睹
('du2', '覩
('du2', '赌
du3 Details
('du3', '著
('du3', '蠧
('du3', '蠹
du5 Details
('du5', '橱
('du5', '蹰


dua3 Details
('dua3', '带
dua6 Details
('dua6', '拕
('dua6', '舵
dua7 Details
('dua7', '大


duah4 Details
('duah4', '叱
('duah4', '咄
('duah4', '喝
duah8 Details
('duah8', '辣



duan1 Details
('duan1', '丹
('duan1', '单
duan3 Details
('duan3', '旦
duan5 Details
('duan5', '坛
duan6 Details
('duan6', '惰
('duan6', '憜
('duan6', '懒
duan7 Details
('duan7', '弹


dug4 Details
('dug4', '咄
dug8 Details
('dug8', '凸
('dug8', '揬
('dug8', '术
('dug8', '柮
('dug8', '突
('dug8', '葖


duh8 Details
('duh8', '剟
('duh8', '矞


dui1 Details
('dui1', '堆
('dui1', '椎
('dui1', '追
dui3 Details
('dui3', '对
('dui3', '怼
('dui3', '碓
dui5 Details
('dui5', '捶
('dui5', '搥
('dui5', '锤
dui6 Details
('dui6', '坠
('dui6', '堕
dui7 Details
('dui7', '缒
('dui7', '膇
('dui7', '镦
('dui7', '队


dung1 Details
('dung1', '吨
('dung1', '囤
('dung1', '堆
('dung1', '墩
('dung1', '墪
('dung1', '屯
('dung1', '惇
('dung1', '撴
('dung1', '敦
('dung1', '暾
('dung1', '盹
('dung1', '礅
('dung1', '窀
('dung1', '肫
('dung1', '谆
('dung1', '蹲
('dung1', '蹾
('dung1', '迍
dung2 Details
('dung2', '盾
('dung2', '趸
('dung2', '𣎴
dung3 Details
('dung3', '扽
dung5 Details
('dung5', '唇
('dung5', '漘
('dung5', '脣
dung6 Details
('dung6', '沌
('dung6', '炖
('dung6', '砘
('dung6', '遁
('dung6', '遯
('dung6', '钝
('dung6', '顿


duê3 Details
('duê3', '缀
('duê3', '裰
duê6 Details
('duê6', '兌
('duê6', '兑


duêg4 Details
('duêg4', '敠


duêng1 Details
('duêng1', '端
duêng3 Details
('duêng3', '断
('duêng3', '煅
('duêng3', '锻
duêng6 Details
('duêng6', '彖
('duêng6', '断
('duêng6', '段
('duêng6', '篆
('duêng6', '簖


dê5 Details
('dê5', '茶


dêg4 Details
('dêg4', '嫡
('dêg4', '德
('dêg4', '惪
('dêg4', '竹
('dêg4', '竺
('dêg4', '踯
dêg8 Details
('dêg8', '值
('dêg8', '嘀
('dêg8', '妯
('dêg8', '扚
('dêg8', '擢
('dêg8', '敌
('dêg8', '涤
('dêg8', '濯
('dêg8', '特
('dêg8', '狄
('dêg8', '的
('dêg8', '笛
('dêg8', '翟
('dêg8', '舳
('dêg8', '荻
('dêg8', '菂
('dêg8', '蛰
('dêg8', '蹢
('dêg8', '轴
('dêg8', '迪
('dêg8', '逖
('dêg8', '逷
('dêg8', '镝
('dêg8', '鹿


dên3 Details
('dên3', '诈
dên7 Details
('dên7', '郑


dêng1 Details
('dêng1', '丁
('dêng1', '仃
('dêng1', '叮
('dêng1', '噔
('dêng1', '征
('dêng1', '徵
('dêng1', '灯
('dêng1', '玎
('dêng1', '町
('dêng1', '疔
('dêng1', '症
('dêng1', '登
('dêng1', '耵
('dêng1', '蹬
('dêng1', '酊
('dêng1', '钉
('dêng1', '靪
dêng2 Details
('dêng2', '戥
('dêng2', '等
('dêng2', '顶
dêng3 Details
('dêng3', '中
('dêng3', '凳
('dêng3', '櫈
('dêng3', '盯
('dêng3', '矴
('dêng3', '碇
('dêng3', '磴
('dêng3', '订
('dêng3', '钉
('dêng3', '镫
('dêng3', '饤
dêng5 Details
('dêng5', '亭
('dêng5', '婷
('dêng5', '尘
('dêng5', '葶
('dêng5', '重
dêng6 Details
('dêng6', '定
('dêng6', '淀
('dêng6', '绽
('dêng6', '腚
('dêng6', '邓
('dêng6', '郑
('dêng6', '锭


e1 Details
('e1', '于
e2 Details
('e2', '与
('e2', '予
e3 Details
('e3', '噁
('e3', '恶
('e3', '淤
('e3', '瘀
('e3', '翳
('e3', '饫
e5 Details
('e5', '予
('e5', '余
('e5', '妤
('e5', '欤
('e5', '狳
('e5', '玙
('e5', '畬
('e5', '舁
('e5', '舆
('e5', '馀
e6 Details
('e6', '与
('e6', '忬
('e6', '滪
('e6', '蓣
('e6', '誉
('e6', '豫
('e6', '预
e7 Details
('e7', '与


eng1 Details
('eng1', '恩
('eng1', '摁
('eng1', '蒽
eng2 Details
('eng2', '瘾
('eng2', '隐


êg4 Details
('êg4', '溢
('êg4', '缢
('êg4', '臆
('êg4', '镒
êg8 Details
('êg8', '亦
('êg8', '亿
('êg8', '埸
('êg8', '奕
('êg8', '峄
('êg8', '弈
('êg8', '弋
('êg8', '忆
('êg8', '怿
('êg8', '掖
('êg8', '易
('êg8', '浴
('êg8', '液
('êg8', '溢
('êg8', '熤
('êg8', '疫
('êg8', '绎
('êg8', '翊
('êg8', '翌
('êg8', '翼
('êg8', '腋
('êg8', '蜴
('êg8', '译
('êg8', '隘



êh4 Details
('êh4', '厄
('êh4', '嗌
('êh4', '戹
('êh4', '扼
('êh4', '搤
('êh4', '轭



ên5 Details
('ên5', '桁
('ên5', '楹


êng1 Details
('êng1', '嘤
('êng1', '婴
('êng1', '撄
('êng1', '樱
('êng1', '瑛
('êng1', '璎
('êng1', '瘿
('êng1', '缨
('êng1', '罂
('êng1', '翁
('êng1', '膺
('êng1', '英
('êng1', '莺
('êng1', '鞥
('êng1', '鴬
('êng1', '鹦
('êng1', '鹰
êng3 Details
('êng3', '壅
('êng3', '应
('êng3', '蕹
êng5 Details
('êng5', '滢
('êng5', '潆
('êng5', '茔
('êng5', '蓥
('êng5', '霙
êng7 Details
('êng7', '用


ga1 Details
('ga1', '咖
('ga1', '咳
('ga1', '家
('ga1', '尻
('ga1', '旮
('ga1', '肐
('ga1', '胶
('ga1', '虼
('ga1', '铰
ga2 Details
('ga2', '绞
('ga2', '钆
ga3 Details
('ga3', '尕
('ga3', '教
('ga3', '校
('ga3', '滘
('ga3', '漖
('ga3', '玍
('ga3', '窖
('ga3', '较
ga6 Details
('ga6', '咬
('ga6', '齩



gab4 Details
('gab4', '合
('gab4', '哈
('gab4', '蛤
('gab4', '颌
('gab4', '鸽


gag4 Details
('gag4', '各
('gag4', '桷
('gag4', '玨
('gag4', '珏
('gag4', '礐
('gag4', '结
('gag4', '脚
('gag4', '袼
('gag4', '觉
('gag4', '角
('gag4', '轧
('gag4', '铬
gag8 Details
('gag8', '咭



gah4 Details
('gah4', '合
('gah4', '岬
('gah4', '甲
('gah4', '盖
('gah4', '胛
('gah4', '钾
gah8 Details
('gah8', '合


gai1 Details
('gai1', '偕
('gai1', '喈
('gai1', '垓
('gai1', '揩
('gai1', '楷
('gai1', '痎
('gai1', '皆
('gai1', '秸
('gai1', '稭
('gai1', '荄
('gai1', '该
('gai1', '赅
('gai1', '阶
('gai1', '陔
gai3 Details
('gai3', '丐
('gai3', '介
('gai3', '价
('gai3', '匃
('gai3', '匄
('gai3', '尬
('gai3', '届
('gai3', '廨
('gai3', '戒
('gai3', '戤
('gai3', '玠
('gai3', '界
('gai3', '盖
('gai3', '芥
('gai3', '蚧
('gai3', '诫
('gai3', '钙
('gai3', '骱
gai5 Details
('gai5', '个
('gai5', '箇
gai7 Details
('gai7', '个



gam1 Details
('gam1', '坩
('gam1', '泔
('gam1', '甘
('gam1', '疳
('gam1', '监
('gam1', '绀
gam2 Details
('gam2', '䃭
('gam2', '感
('gam2', '橄
gam3 Details
('gam3', '尴
('gam3', '槛
('gam3', '淦
('gam3', '监
('gam3', '鉴
gam5 Details
('gam5', '含


gan1 Details
('gan1', '柑
('gan1', '橄
('gan1', '苷
gan2 Details
('gan2', '敢
('gan2', '澉
gan3 Details
('gan3', '酵
gan5 Details
('gan5', '衔


gang1 Details
('gang1', '乹
('gang1', '乾
('gang1', '亁
('gang1', '公
('gang1', '冈
('gang1', '刚
('gang1', '功
('gang1', '堽
('gang1', '奸
('gang1', '岗
('gang1', '工
('gang1', '干
('gang1', '扛
('gang1', '摃
('gang1', '杆
('gang1', '江
('gang1', '犴
('gang1', '玕
('gang1', '疘
('gang1', '矸
('gang1', '竿
('gang1', '纲
('gang1', '缸
('gang1', '罡
('gang1', '肛
('gang1', '艰
('gang1', '茳
('gang1', '菅
('gang1', '蚣
('gang1', '豇
('gang1', '酐
('gang1', '间
gang2 Details
('gang2', '囝
('gang2', '拣
('gang2', '擀
('gang2', '枧
('gang2', '柬
('gang2', '涧
('gang2', '港
('gang2', '秆
('gang2', '简
('gang2', '耩
('gang2', '讲
('gang2', '锏
gang3 Details
('gang3', '干
('gang3', '幹
('gang3', '旰
('gang3', '杠
('gang3', '榦
('gang3', '槓
('gang3', '绛
('gang3', '谏
('gang3', '贑
('gang3', '赣
('gang3', '锏
('gang3', '降
('gang3', '𧒄
gang7 Details
('gang7', '共



gao1 Details
('gao1', '䴔
('gao1', '交
('gao1', '勾
('gao1', '峧
('gao1', '枸
('gao1', '槔
('gao1', '沟
('gao1', '皋
('gao1', '皐
('gao1', '睾
('gao1', '筊
('gao1', '篝
('gao1', '缑
('gao1', '艽
('gao1', '茭
('gao1', '蛟
('gao1', '跤
('gao1', '郊
('gao1', '钩
('gao1', '鞲
('gao1', '韝
('gao1', '高
('gao1', '鲛
gao2 Details
('gao2', '九
('gao2', '佼
('gao2', '垢
('gao2', '搞
('gao2', '杲
('gao2', '枸
('gao2', '槀
('gao2', '槁
('gao2', '犒
('gao2', '狗
('gao2', '狡
('gao2', '玖
('gao2', '皎
('gao2', '缟
('gao2', '藁
('gao2', '蚼
('gao2', '镐
gao3 Details
('gao3', '到
('gao3', '告
('gao3', '够
('gao3', '诰
('gao3', '郜
('gao3', '锆
gao5 Details
('gao5', '猴
gao6 Details
('gao6', '厚
('gao6', '垢


ge1 Details
('ge1', '居
('ge1', '琚
('ge1', '腒
('ge1', '裾
('ge1', '车
('ge1', '锔
ge2 Details
('ge2', '举
('ge2', '弆
('ge2', '枸
('ge2', '柜
('ge2', '榉
('ge2', '榘
('ge2', '洰
('ge2', '矩
('ge2', '秬
('ge2', '莒
('ge2', '蒟
('ge2', '踽
('ge2', '龋
ge3 Details
('ge3', '锯
ge5 Details
('ge5', '据
ge6 Details
('ge6', '倨
('ge6', '巨
('ge6', '拒
('ge6', '据
('ge6', '澽
('ge6', '炬
('ge6', '秬
('ge6', '苣
('ge6', '讵
('ge6', '距
('ge6', '踞
('ge6', '遽
('ge6', '醵
('ge6', '钜



geng1 Details
('geng1', '光
('geng1', '均
('geng1', '岗
('geng1', '巾
('geng1', '扛
('geng1', '摃
('geng1', '斤
('geng1', '根
('geng1', '筋
('geng1', '筠
('geng1', '缸
('geng1', '跟
('geng1', '鋆
('geng1', '钧
geng2 Details
('geng2', '仅
('geng2', '卷
('geng2', '卺
('geng2', '堇
('geng2', '广
('geng2', '廑
('geng2', '槿
('geng2', '殣
('geng2', '瑾
('geng2', '管
('geng2', '耿
('geng2', '谨
('geng2', '馑
geng3 Details
('geng3', '哏
('geng3', '艮
('geng3', '茛
('geng3', '觐
('geng3', '钢
('geng3', '靳
geng5 Details
('geng5', '凝
geng6 Details
('geng6', '墐
('geng6', '脘
('geng6', '近



gi1 Details
('gi1', '乩
('gi1', '几
('gi1', '剞
('gi1', '叽
('gi1', '基
('gi1', '奇
('gi1', '姬
('gi1', '岐
('gi1', '嵇
('gi1', '支
('gi1', '期
('gi1', '机
('gi1', '枝
('gi1', '栀
('gi1', '玑
('gi1', '畸
('gi1', '畿
('gi1', '矶
('gi1', '稽
('gi1', '笄
('gi1', '箕
('gi1', '肌
('gi1', '萁
('gi1', '讥
('gi1', '饥
gi2 Details
('gi2', '几
('gi2', '己
('gi2', '庋
('gi2', '指
('gi2', '掎
('gi2', '稽
('gi2', '纪
('gi2', '莒
('gi2', '虮
('gi2', '麂
gi3 Details
('gi3', '偈
('gi3', '厩
('gi3', '既
('gi3', '暨
('gi3', '痣
('gi3', '纪
('gi3', '继
('gi3', '罽
('gi3', '蓟
('gi3', '觊
('gi3', '计
('gi3', '记
('gi3', '髻
gi5 Details
('gi5', '旂
('gi5', '旗
('gi5', '棋
gi6 Details
('gi6', '企
('gi6', '伎
('gi6', '冀
('gi6', '垍
('gi6', '妓
('gi6', '屦
('gi6', '徛
('gi6', '忌
('gi6', '忮
('gi6', '惎
('gi6', '技
('gi6', '洎
('gi6', '窭
('gi6', '羁
('gi6', '跽
('gi6', '骥
gi7 Details
('gi7', '己


gia1 Details
('gia1', '伽
('gia1', '佳
('gia1', '加
('gia1', '咖
('gia1', '嘉
('gia1', '家
('gia1', '珈
('gia1', '痂
('gia1', '笳
('gia1', '茄
('gia1', '葭
('gia1', '跏
('gia1', '迦
gia2 Details
('gia2', '假
('gia2', '叚
('gia2', '斝
('gia2', '槚
('gia2', '贾
gia3 Details
('gia3', '寄


giah4 Details
('giah4', '揭
('giah4', '撅
('giah4', '讦
giah8 Details
('giah8', '剧
('giah8', '噱
('giah8', '屐



gian1 Details
('gian1', '京
('gian1', '惊
('gian1', '猄
('gian1', '经
('gian1', '麖
gian2 Details
('gian2', '仔
('gian2', '假
('gian2', '囝
gian3 Details
('gian3', '镜
gian5 Details
('gian5', '行
gian6 Details
('gian6', '件
gian7 Details
('gian7', '健


giang1 Details
('giang1', '僵
('giang1', '姜
('giang1', '殭
('giang1', '畺
('giang1', '疆
('giang1', '礓
('giang1', '缰
('giang1', '羌
('giang1', '羗
('giang1', '蜣
giang2 Details
('giang2', '强
('giang2', '膙
('giang2', '镪
giang6 Details
('giang6', '犟
('giang6', '腱


gib4 Details
('gib4', '伋
('gib4', '急
('gib4', '给
gib8 Details
('gib8', '及
('gib8', '芨



gig4 Details
('gig4', '佶
('gig4', '吉
('gig4', '姞
('gig4', '揭
('gig4', '桔
('gig4', '橘
('gig4', '碣
('gig4', '结
('gig4', '鲒


gih4 Details
('gih4', '砌



gim1 Details
('gim1', '今
('gim1', '金
gim2 Details
('gim2', '锦
gim3 Details
('gim3', '噤
('gim3', '禁
gim6 Details
('gim6', '妗


gin3 Details
('gin3', '见
gin5 Details
('gin5', '墘
('gin5', '舷


ging2 Details
('ging2', '紧
ging3 Details
('ging3', '腱


giog4 Details
('giog4', '掬
('giog4', '粥
('giog4', '脚
('giog4', '鞠
('giog4', '鞫
('giog4', '


giong1 Details
('giong1', '共
('giong1', '塨
('giong1', '恭
('giong1', '穹
('giong1', '躬
('giong1', '躳
('giong1', '駉
giong2 Details
('giong2', '囧
('giong2', '拱
('giong2', '颎


giu1 Details
('giu1', '龟
giu2 Details
('giu2', '九
('giu2', '玖
('giu2', '艽
('giu2', '赳
giu3 Details
('giu3', '厩
('giu3', '捄
('giu3', '救
('giu3', '疚
('giu3', '究
giu5 Details
('giu5', '球
giu6 Details
('giu6', '咎
('giu6', '柩
('giu6', '疚
('giu6', '纠



giê3 Details
('giê3', '叫
giê5 Details
('giê5', '桥
('giê5', '茄
giê6 Details
('giê6', '藠
giê7 Details
('giê7', '轿


giêg4 Details
('giêg4', '偈
('giêg4', '尜
('giêg4', '恝
('giêg4', '洁
('giêg4', '碣
('giêg4', '羯
giêg8 Details
('giêg8', '杰
('giêg8', '桀
('giêg8', '竭


giêm5 Details
('giêm5', '咸


giên1 Details
('giên1', '姜
('giên1', '薑


giêng1 Details
('giêng1', '坚
('giêng1', '娟
('giêng1', '悭
('giêng1', '捐
('giêng1', '涓
('giêng1', '蜎
('giêng1', '蠲
('giêng1', '铿
('giêng1', '鲣
('giêng1', '鹃
giêng2 Details
('giêng2', '瀽
giêng3 Details
('giêng3', '建
('giêng3', '狷
('giêng3', '獧
('giêng3', '绢
('giêng3', '罥
('giêng3', '见
('giêng3', '鄄
giêng6 Details
('giêng6', '健
('giêng6', '建
('giêng6', '毽
('giêng6', '犍
('giêng6', '键
('giêng6', '鞬


go1 Details
('go1', '哥
('go1', '歌
('go1', '滒
('go1', '竿
('go1', '篙
('go1', '糕
('go1', '羔
('go1', '膏
('go1', '謌
('go1', '过
('go1', '餻
('go1', '高
go2 Details
('go2', '槀
('go2', '槁
('go2', '稾
('go2', '稿
('go2', '缟
('go2', '蜾
('go2', '裹
go3 Details
('go3', '划
('go3', '告
('go3', '块
go5 Details
('go5', '挝
('go5', '笱
go6 Details
('go6', '个



gog4 Details
('gog4', '䀰
('gog4', '咯
('gog4', '国
('gog4', '峪
('gog4', '帼
('gog4', '掴
('gog4', '榖
('gog4', '毂
('gog4', '瀔
('gog4', '腘
('gog4', '蝈
('gog4', '觳
('gog4', '谷
('gog4', '馘


goh4 Details
('goh4', '搁
('goh4', '胳
('goh4', '阁



goi1 Details
('goi1', '街
('goi1', '鶏
('goi1', '鸡
goi2 Details
('goi2', '改
('goi2', '檞
('goi2', '解
goi3 Details
('goi3', '疥
('goi3', '解
('goi3', '计
goi5 Details
('goi5', '膎
('goi5', '鲑
goi7 Details
('goi7', '慧
('goi7', '易



goih4 Details
('goih4', '圿
('goih4', '夹
('goih4', '荚
('goih4', '袷
('goih4', '裌
goih8 Details
('goih8', '夹
('goih8', '挟


goin1 Details
('goin1', '肩
('goin1', '间
goin2 Details
('goin2', '茧
('goin2', '裥
('goin2', '趼
goin3 Details
('goin3', '间


gong1 Details
('gong1', '公
('gong1', '功
('gong1', '工
('gong1', '攻
('gong1', '蚣
('gong1', '龚
gong2 Details
('gong2', '栱
('gong2', '珙
('gong2', '讲
gong3 Details
('gong3', '唝
('gong3', '戆
('gong3', '杠
('gong3', '槓
('gong3', '汞
('gong3', '贡
('gong3', '銾
gong5 Details
('gong5', '戆


gou1 Details
('gou1', '估
('gou1', '姑
('gou1', '孤
('gou1', '枯
('gou1', '沽
('gou1', '罛
('gou1', '苽
('gou1', '菇
('gou1', '菰
('gou1', '辜
('gou1', '酤
('gou1', '鸪
gou2 Details
('gou2', '估
('gou2', '古
('gou2', '嘏
('gou2', '牯
('gou2', '皷
('gou2', '瞽
('gou2', '笱
('gou2', '羖
('gou2', '股
('gou2', '臌
('gou2', '苟
('gou2', '诂
('gou2', '钴
('gou2', '鼓
gou3 Details
('gou3', '僱
('gou3', '冓
('gou3', '垢
('gou3', '够
('gou3', '妒
('gou3', '妬
('gou3', '媾
('gou3', '构
('gou3', '菟
('gou3', '觏
('gou3', '诟
('gou3', '购
('gou3', '遘
('gou3', '雇
('gou3', '顾
gou5 Details
('gou5', '糊
gou6 Details
('gou6', '靠


gu1 Details
('gu1', '佝
('gu1', '劬
('gu1', '呱
('gu1', '咕
('gu1', '孤
('gu1', '岣
('gu1', '泃
('gu1', '痀
('gu1', '蛄
('gu1', '觚
('gu1', '轱
('gu1', '辜
('gu1', '驹
('gu1', '骷
('gu1', '鸪
('gu1', '鸲
('gu1', '龟
gu2 Details
('gu2', '久
('gu2', '古
('gu2', '盬
('gu2', '罟
('gu2', '蛊
('gu2', '诂
('gu2', '贾
('gu2', '韭
('gu2', '韮
gu3 Details
('gu3', '句
('gu3', '固
('gu3', '堌
('gu3', '崮
('gu3', '故
('gu3', '灸
('gu3', '痼
('gu3', '锢
('gu3', '顾
('gu3', '鲴
gu6 Details
('gu6', '俱
('gu6', '具
('gu6', '惧
('gu6', '犋
('gu6', '舅
('gu6', '飓
gu7 Details
('gu7', '故
('gu7', '旧


gua1 Details
('gua1', '呱
('gua1', '柯
gua2 Details
('gua2', '剐
('gua2', '寡
gua3 Details
('gua3', '挂
('gua3', '旰
('gua3', '盖
('gua3', '褂


guah4 Details
('guah4', '割
('guah4', '噶
('guah4', '渴
('guah4', '葛


guai1 Details
('guai1', '乖
('guai1', '鲑
guai2 Details
('guai2', '拐
('guai2', '枴
guai3 Details
('guai3', '会
('guai3', '侩
('guai3', '刽
('guai3', '哙
('guai3', '怪
('guai3', '恠
('guai3', '桧
('guai3', '狯
('guai3', '绘
('guai3', '缋
('guai3', '脍
('guai3', '蒯
('guai3', '郐



guain2 Details
('guain2', '果


guan1 Details
('guain1', '乹
('guain1', '乾
('guain1', '亁
('guain1', '倌
('guain1', '官
('guain1', '干
('guain1', '杆
('guain1', '棺
('guain1', '秆
('guain1', '竿
('guain1', '肝
guan2 Details
('guain2', '果
('guain2', '赶
guan5 Details
('guain5', '寒
guan7 Details
('guain7', '汗



guang1 Details
('guang1', '光
('guang1', '桄
('guang1', '洸
('guang1', '胱
('guang1', '觥
('guang1', '觵
('guang1', '诓
('guang1', '诳
('guang1', '鳏
guang2 Details
('guang2', '䌹
('guang2', '冏
('guang2', '广
('guang2', '泂
('guang2', '炅
('guang2', '炯
('guang2', '烱
('guang2', '耿
('guang2', '诇
('guang2', '迥
('guang2', '逈
guang6 Details
('guang6', '逛


gug4 Details
('gug4', '榾
('gug4', '蓇
('gug4', '馉
('gug4', '骨
('gug4', '鹘
gug8 Details
('gug8', '崛
('gug8', '掘
('gug8', '汩
('gug8', '滑
('gug8', '猾


gui1 Details
('gui1', '喹
('gui1', '圭
('gui1', '奎
('gui1', '妫
('gui1', '归
('gui1', '珪
('gui1', '皈
('gui1', '硅
('gui1', '窥
('gui1', '蝰
('gui1', '规
('gui1', '邽
('gui1', '闺
('gui1', '鲑
gui2 Details
('gui2', '傀
('gui2', '几
('gui2', '宄
('gui2', '庋
('gui2', '诡
('gui2', '鬼
gui3 Details
('gui3', '悸
('gui3', '桂
('gui3', '炅
('gui3', '瑰
('gui3', '瓌
('gui3', '癸
('gui3', '筀
('gui3', '贵
('gui3', '鳜


guin3 Details
('guin3', '惯
guin5 Details
('guin5', '危
('guin5', '悬
guin6 Details
('guin6', '跪
guin7 Details
('guin7', '县
('guin7', '柜


gung1 Details
('gung1', '军
('gung1', '君
('gung1', '皲
('gung1', '麇
('gung1', '麕
gung2 Details
('gung2', '涫
('gung2', '滚
('gung2', '磙
('gung2', '绲
('gung2', '辊
('gung2', '鲧
gung3 Details
('gung3', '棍
gung5 Details
('gung5', '帬
('gung5', '裙
gung6 Details
('gung6', '捃
('gung6', '珺
('gung6', '郡


guê1 Details
('guê1', '涡
('guê1', '濄
('guê1', '瓜
('guê1', '胍
guê2 Details
('guê2', '果
('guê2', '粿
('guê2', '裹
('guê2', '馃
guê3 Details
('guê3', '怪
('guê3', '挂
('guê3', '过
('guê3', '髻



guêg4 Details
('guêg4', '决
('guêg4', '刮
('guêg4', '孓
('guêg4', '崞
('guêg4', '廓
('guêg4', '抉
('guêg4', '括
('guêg4', '栝
('guêg4', '椁
('guêg4', '炔
('guêg4', '玦
('guêg4', '聒
('guêg4', '蛞
('guêg4', '觖
('guêg4', '诀
('guêg4', '谲
('guêg4', '鐍
('guêg4', '駃
('guêg4', '鸹



guêh4 Details
('guêh4', '刮
('guêh4', '漷
('guêh4', '蹶
('guêh4', '郭
guêh8 Details
('guêh8', '橛
('guêh8', '橜


guên1 Details
('guên1', '关
guên2 Details
('guên2', '果


guêng1 Details
('guêng1', '关
('guêng1', '冠
('guêng1', '瘝
('guêng1', '纶
('guêng1', '观
guêng2 Details
('guêng2', '琯
('guêng2', '管
('guêng2', '莞
('guêng2', '逭
('guêng2', '馆
guêng3 Details
('guêng3', '冠
('guêng3', '券
('guêng3', '惯
('guêng3', '掼
('guêng3', '桊
('guêng3', '灌
('guêng3', '瓘
('guêng3', '盥
('guêng3', '眷
('guêng3', '睠
('guêng3', '祼
('guêng3', '罐
('guêng3', '观
('guêng3', '贯
('guêng3', '鏆
('guêng3', '鹳
guêng6 Details
('guêng6', '倦
('guêng6', '勌
('guêng6', '卷


gê1 Details
('gê1', '加
('gê1', '家
('gê1', '袈
('gê1', '镓
gê2 Details
('gê2', '假
('gê2', '叚
gê3 Details
('gê3', '价
('gê3', '嫁
('gê3', '架
('gê3', '稼
('gê3', '驾
gê5 Details
('gê5', '枷
gê6 Details
('gê6', '下


gêg4 Details
('gêg4', '亟
('gêg4', '墼
('gêg4', '戟
('gêg4', '棘
('gêg4', '檄
('gêg4', '殛
('gêg4', '激
('gêg4', '缂
('gêg4', '菊
('gêg4', '衋
('gêg4', '革
gêg8 Details
('gêg8', '局
('gêg8', '极
('gêg8', '湨
('gêg8', '跼
('gêg8', '锔


gêh4 Details
('gêh4', '嗝
('gêh4', '格
('gêh4', '滆
('gêh4', '翮
('gêh4', '胳
('gêh4', '膈
('gêh4', '镉
('gêh4', '隔
('gêh4', '骼
gêh8 Details
('gêh8', '硌
('gêh8', '逆



gên1 Details
('gên1', '庚
('gên1', '畊
('gên1', '经
('gên1', '羹
('gên1', '耕
('gên1', '赓
('gên1', '鹒
gên2 Details
('gên2', '哽
('gên2', '埂
('gên2', '梗
('gên2', '绠
('gên2', '鲠
gên3 Details
('gên3', '刭
('gên3', '劲
('gên3', '径
('gên3', '更
('gên3', '粇
('gên3', '粳
('gên3', '迳
('gên3', '颈


gêng1 Details
('gêng1', '供
('gêng1', '兢
('gêng1', '宫
('gêng1', '弓
('gêng1', '惊
('gêng1', '更
('gêng1', '泾
('gêng1', '矜
('gêng1', '经
('gêng1', '荆
gêng2 Details
('gêng2', '境
('gêng2', '憬
('gêng2', '景
('gêng2', '獍
('gêng2', '璟
('gêng2', '竟
gêng3 Details
('gêng3', '亘
('gêng3', '敬
('gêng3', '更
('gêng3', '筻
gêng6 Details
('gêng6', '儆
('gêng6', '竞
('gêng6', '警


ghai7 Details
('ghai7', '碍


ghaoh8 Details
('ghaoh8', '乐



ghe2 Details
('ghe2', '语
ghe6 Details
('ghe6', '御
('ghe6', '驭
ghe7 Details
('ghe7', '御



ghi5 Details
('ghi5', '嶷
('ghi5', '疑



ghia3 Details
('ghia3', '讶
('ghia3', '迓


gho5 Details
('gho5', '鹅
gho7 Details
('gho7', '饿


ghoi5 Details
('ghoi5', '倪
ghoi7 Details
('ghoi7', '呓
('ghoi7', '艺
('ghoi7', '蓺


ghou5 Details
('ghou5', '吴
('ghou5', '蜈
('ghou5', '鯃
ghou7 Details
('ghou7', '误


ghu5 Details
('ghu5', '牛


ghua7 Details
('ghua7', '外


ghui7 Details
('ghui7', '魏



ghuêh8 Details
('ghuêh8', '月
('ghuêh8', '玥
('ghuêh8', '钥



ghê5 Details
('ghê5', '伢
('ghê5', '岈
('ghê5', '牙
('ghê5', '玡
('ghê5', '芽
('ghê5', '蚜
('ghê5', '蜈
('ghê5', '衙
('ghê5', '釾
ghê7 Details
('ghê7', '砑


ghêg8 Details
('ghêg8', '狱
('ghêg8', '玉
('ghêg8', '钰


ha1 Details
('ha1', '哈
ha3 Details
('ha3', '孝


hab8 Details
('hab8', '合
('hab8', '峡



hag4 Details
('hag4', '劐
('hag4', '喝
('hag4', '壑
('hag4', '曷
('hag4', '洫
('hag4', '涸
('hag4', '瞎
('hag4', '耠
('hag4', '蓄
('hag4', '蝎
('hag4', '蠍
('hag4', '蠚
('hag4', '褐
('hag4', '谒
('hag4', '豁
('hag4', '辖
('hag4', '遏
('hag4', '郝
('hag4', '鞨
hag8 Details
('hag8', '乏
('hag8', '学
('hag8', '峃
('hag8', '翯



hah4 Details
('hah4', '哈
('hah4', '瓣
('hah4', '铪
('hah4', '饸
hah8 Details
('hah8', '合
('hah8', '郃



hai2 Details
('hai2', '嗨
('hai2', '海
('hai2', '醢
hai5 Details
('hai5', '孩
('hai5', '谐
('hai5', '颏
('hai5', '骸
hai6 Details
('hai6', '亥
('hai6', '咳
('hai6', '孩
('hai6', '廨
('hai6', '懈
('hai6', '械
('hai6', '欬
('hai6', '氦
('hai6', '澥
('hai6', '瀣
('hai6', '獬
('hai6', '胲
('hai6', '薤
('hai6', '解
('hai6', '邂
('hai6', '骇
hai7 Details
('hai7', '嗐
('hai7', '害


ham1 Details
('ham1', '憨
('ham1', '蚶
('ham1', '邯
('ham1', '酣
ham2 Details
('ham2', '撼
ham3 Details
('ham3', '喊
('ham3', '撖
ham5 Details
('ham5', '函
('ham5', '含
('ham5', '咸
('ham5', '圅
('ham5', '晗
('ham5', '浛
('ham5', '涵
('ham5', '焓
('ham5', '菡
('ham5', '衔
('ham5', '颔
ham6 Details
('ham6', '憾
ham7 Details
('ham7', '陷


hang1 Details
('hang1', '烘
('hang1', '熯
('hang1', '犺
('hang1', '顸
('hang1', '鼾
hang2 Details
('hang2', '夯
('hang2', '悍
('hang2', '扞
('hang2', '捍
('hang2', '桿
('hang2', '汗
('hang2', '焊
('hang2', '猂
('hang2', '罕
('hang2', '銲
hang3 Details
('hang3', '汉
hang5 Details
('hang5', '㤚
('hang5', '寒
('hang5', '斻
('hang5', '杭
('hang5', '汗
('hang5', '沆
('hang5', '瀚
('hang5', '珩
('hang5', '绗
('hang5', '翰
('hang5', '航
('hang5', '行
('hang5', '迒
('hang5', '邗
('hang5', '降
('hang5', '韩
('hang5', '颃
hang6 Details
('hang6', '限
('hang6', '项
hang7 Details
('hang7', '巷


hao1 Details
('hao1', '号
('hao1', '哮
('hao1', '嗥
('hao1', '噑
('hao1', '嚆
('hao1', '浩
('hao1', '淏
('hao1', '蒿
('hao1', '薅
('hao1', '虓
('hao1', '酵
('hao1', '鸮
('hao1', '齁
hao2 Details
('hao2', '吼
('hao2', '好
('hao2', '昊
('hao2', '滈
('hao2', '灏
('hao2', '皓
('hao2', '皞
('hao2', '镐
('hao2', '颢
hao3 Details
('hao3', '孝
hao5 Details
('hao5', '嚎
('hao5', '壕
('hao5', '毫
('hao5', '濠
('hao5', '豪
hao6 Details
('hao6', '后
('hao6', '後
('hao6', '校
('hao6', '淏
hao7 Details
('hao7', '俲
('hao7', '候
('hao7', '堠
('hao7', '效
('hao7', '鲎


haon3 Details
('haon3', '好



he1 Details
('he1', '嘘
('he1', '圩
('he1', '墟
('he1', '歔
('he1', '虚
he2 Details
('he2', '浒
('he2', '许
he5 Details
('he5', '渔
('he5', '鱼



heng1 Details
('heng1', '䜣
('heng1', '俽
('heng1', '忻
('heng1', '轩
heng2 Details
('heng2', '很
('heng2', '狠
heng6 Details
('heng6', '恨
('heng6', '远



hi1 Details
('hi1', '僖
('hi1', '兮
('hi1', '唏
('hi1', '嘻
('hi1', '嬉
('hi1', '希
('hi1', '晞
('hi1', '曦
('hi1', '欷
('hi1', '浠
('hi1', '烯
('hi1', '熈
('hi1', '熙
('hi1', '熹
('hi1', '熺
('hi1', '燨
('hi1', '爔
('hi1', '牺
('hi1', '禧
('hi1', '稀
('hi1', '絺
('hi1', '羲
('hi1', '譆
('hi1', '豨
('hi1', '郗
('hi1', '醯
('hi1', '颐
hi2 Details
('hi2', '喜
('hi2', '蟢
hi3 Details
('hi3', '呬
('hi3', '戏
('hi3', '饩
hi5 Details
('hi5', '奚
('hi5', '徯
('hi5', '畦
('hi5', '蹊
('hi5', '鼷
hi6 Details
('hi6', '勚
('hi6', '拽
('hi6', '携
('hi6', '曳
('hi6', '盻
('hi6', '禊
('hi6', '系
('hi6', '繋



hia3 Details
('hia3', '罅
hia5 Details
('hia5', '暇
('hia5', '瑕
('hia5', '遐
('hia5', '霞
('hia5', '騢
hia6 Details
('hia6', '下
('hia6', '瓦
('hia6', '蚁



hiah4 Details
('hiah4', '歇
hiah8 Details
('hiah4', '役
('hiah4', '额



hiam2 Details
('hiam2', '猃
('hiam2', '险
hiam5 Details
('hiam5', '嫌



hian1 Details
('hian1', '兄
hian5 Details
('hian5', '邢
('hian5', '顏
('hian5', '颜
hian7 Details
('hian7', '艾



hiang1 Details
('hiang1', '乡
('hiang1', '芗
('hiang1', '香
hiang2 Details
('hiang2', '享
('hiang2', '响
('hiang2', '垧
('hiang2', '晌
('hiang2', '飨
hiang3 Details
('hiang3', '向
('hiang3', '饷



hib4 Details
('hib4', '噏
('hib4', '歙
('hib4', '熻
('hib4', '翕



hig4 Details
('hig4', '肸



him1 Details
('him1', '歆
('him1', '鑫
him5 Details
('him5', '熊



hin5 Details
('hin5', '弦
('hin5', '絃
('hin5', '舷
hin6 Details
('hin6', '耳



hing5 Details
('hing5', '眩
hing7 Details
('hing7', '现
('hing7', '见



hiog4 Details
('hiog4', '勖
('hiog4', '勗
('hiog4', '彧
('hiog4', '旭
('hiog4', '昱
('hiog4', '晔
('hiog4', '毓
('hiog4', '煜
('hiog4', '燠
('hiog4', '郁
('hiog4', '顼
('hiog4', '馥


hiong1 Details
('hiong1', '凶
('hiong1', '匈
('hiong1', '汹
('hiong1', '讻
hiong5 Details
('hiong5', '雄



hiun1 Details
('hiun1', '休
('hiun1', '咻
('hiun1', '幽
('hiun1', '庥
('hiun1', '悠
('hiun1', '攸
('hiun1', '貅
('hiun1', '髹
('hiun1', '鸺
('hiun1', '麀
hiun2 Details
('hiun2', '朽
hiun3 Details
('hiun3', '嗅
('hiun3', '溴
('hiun3', '糗
('hiun3', '臭


hiêh8 Details
('hiêh8', '叶
('hiêh8', '页



hiên1 Details
('hiên1', '乡
('hiên1', '香
hiên3 Details
('hiên3', '向



hiêng1 Details
('hiêng1', '禤
hiêng2 Details
('hiêng2', '显
('hiêng2', '烜
hiêng3 Details
('hiêng3', '宪
('hiêng3', '岘
('hiêng3', '献
('hiêng3', '绚
('hiêng3', '衅
('hiêng3', '谳
hiêng5 Details
('hiêng5', '娴
('hiêng5', '悬
('hiêng5', '泫
('hiêng5', '炫
('hiêng5', '玄
('hiêng5', '痃
('hiêng5', '痫
('hiêng5', '眩
('hiêng5', '舷
('hiêng5', '贤
('hiêng5', '铉
('hiêng5', '鹇



hng1 Details
('hng1', '勋
('hng1', '哼
('hng1', '埙
('hng1', '掀
('hng1', '方
('hng1', '昕
('hng1', '欣
('hng1', '殷
('hng1', '炘
('hng1', '祅
('hng1', '荒
('hng1', '轩
('hng1', '醺
('hng1', '锨
hng2 Details
('hng2', '哼
('hng2', '啈
hng5 Details
('hng5', '园



hngh4 Details
('hngh4', '擤



ho1 Details
('ho1', '呵
('ho1', '熇
('ho1', '犺
('ho1', '诃
ho2 Details
('ho2', '好
ho3 Details
('ho3', '囮
('ho3', '耗
('ho3', '荷
('ho3', '讹
ho5 Details
('ho5', '何
('ho5', '合
('ho5', '河
('ho5', '荷
ho6 Details
('ho6', '和
ho7 Details
('ho7', '号
('ho7', '好
('ho7', '贺


hog4 Details
('hog4', '复
('hog4', '福
('hog4', '蝠
('hog4', '蝮
('hog4', '辐
('hog4', '鹖
hog8 Details
('hog8', '伏
('hog8', '域
('hog8', '复
('hog8', '惑
('hog8', '或
('hog8', '斛
('hog8', '服
('hog8', '栿
('hog8', '棫
('hog8', '槲
('hog8', '洑
('hog8', '茯
('hog8', '菔
('hog8', '蜮
('hog8', '袱
('hog8', '覆
('hog8', '魊
('hog8', '鳆
('hog8', '


hoh4 Details
('hoh4', '熇
('hoh4', '翕
('hoh4', '酷
hoh8 Details
('hoh8', '鹤



hoi6 Details
('hoi6', '蟹
('hoi6', '蠏


hoin2 Details
('hoin2', '蚬
hoin5 Details
('hoin5', '还
hoin6 Details
('hoin6', '阂
('hoin6', '阖
hoin7 Details
('hoin7', '苋



hong1 Details
('hong1', '丰
('hong1', '吽
('hong1', '哄
('hong1', '封
('hong1', '峯
('hong1', '峰
('hong1', '沣
('hong1', '沨
('hong1', '渢
('hong1', '烘
('hong1', '烽
('hong1', '砜
('hong1', '葑
('hong1', '訇
('hong1', '轰
('hong1', '酆
('hong1', '锋
('hong1', '风
hong2 Details
('hong2', '俸
('hong2', '哄
('hong2', '唪
('hong2', '蚌
('hong2', '蜯
hong3 Details
('hong3', '哄
('hong3', '蕻
('hong3', '讧
('hong3', '讽
('hong3', '赗
hong5 Details
('hong5', '宏
('hong5', '弘
('hong5', '泓
('hong5', '洪
('hong5', '烘
('hong5', '竑
('hong5', '红
('hong5', '缝
('hong5', '翃
('hong5', '肱
('hong5', '荭
('hong5', '葓
('hong5', '蕻
('hong5', '虹
('hong5', '逢
('hong5', '鋐
('hong5', '闳
('hong5', '鸿
('hong5', '黉
hong6 Details
('hong6', '凤
('hong6', '奉


hou1 Details
('hou1', '呼
hou2 Details
('hou2', '否
hou3 Details
('hou3', '戽
hou5 Details
('hou5', '侯
('hou5', '狐
('hou5', '瘊
('hou5', '矦
('hou5', '篌
('hou5', '糇
('hou5', '糊
('hou5', '胡
('hou5', '葫
('hou5', '骺
hou6 Details
('hou6', '后
('hou6', '垕
('hou6', '户
('hou6', '逅
('hou6', '雨
hou7 Details
('hou7', '互



houn2 Details
('houn2', '不
('houn2', '琥
('houn2', '虎
houn5 Details
('houn5', '唬


hu1 Details
('hu1', '乎
('hu1', '伕
('hu1', '俘
('hu1', '呼
('hu1', '嘑
('hu1', '夫
('hu1', '孚
('hu1', '孵
('hu1', '敷
('hu1', '滹
('hu1', '烀
('hu1', '稃
('hu1', '粰
('hu1', '肤
('hu1', '腐
('hu1', '莩
('hu1', '趺
('hu1', '跗
('hu1', '轷
('hu1', '郛
('hu1', '鈇
('hu1', '麸
hu2 Details
('hu2', '俯
('hu2', '府
('hu2', '拊
('hu2', '栩
('hu2', '浒
('hu2', '滏
('hu2', '父
('hu2', '缶
('hu2', '腑
('hu2', '许
('hu2', '诩
('hu2', '釜
('hu2', '頫
hu3 Details
('hu3', '仆
('hu3', '付
('hu3', '傅
('hu3', '副
('hu3', '咐
('hu3', '讣
('hu3', '赋
('hu3', '赙
('hu3', '赴
hu5 Details
('hu5', '凫
('hu5', '和
('hu5', '壶
('hu5', '弧
('hu5', '扶
('hu5', '煳
('hu5', '狐
('hu5', '猢
('hu5', '瑚
('hu5', '符
('hu5', '糊
('hu5', '胡
('hu5', '芙
('hu5', '葫
('hu5', '蚨
('hu5', '蝴
('hu5', '醐
('hu5', '餬
('hu5', '鹕
hu6 Details
('hu6', '互
('hu6', '冱
('hu6', '坿
('hu6', '妇
('hu6', '岵
('hu6', '怙
('hu6', '扈
('hu6', '护
('hu6', '沍
('hu6', '沪
('hu6', '煦
('hu6', '瓠
('hu6', '祜
('hu6', '蠖
('hu6', '负
('hu6', '辅
('hu6', '鄠
('hu6', '酗
('hu6', '阜
('hu6', '附
('hu6', '驸
('hu6', '鲋
hu7 Details
('hu7', '夫
('hu7', '腐


hua1 Details
('hua1', '划
('hua1', '华
('hua1', '哗
('hua1', '花
hua5 Details
('hua5', '划
('hua5', '华
('hua5', '咊
('hua5', '和
('hua5', '桦
('hua5', '禾
('hua5', '踝
('hua5', '铧
('hua5', '骅
hua6 Details
('hua6', '祸
hua7 Details
('hua7', '嚯


huab4 Details
('huab4', '法
('huab4', '灋
('huab4', '珐
('huab4', '砝


huag8 Details
('huag8', '矱



huah4 Details
('huah4', '㕦
('huah4', '划
('huah4', '刮
('huah4', '劃
('huah4', '喝
huah8 Details
('huah8', '伐


huai2 Details
('huai2', '侉
huai5 Details
('huai5', '佪
('huai5', '徊
('huai5', '怀
('huai5', '槐
('huai5', '淮
('huai5', '耲
huai6 Details
('huai6', '坏


huam3 Details
('huam3', '泛
huam5 Details
('huam5', '凡
('huam5', '矾
huam6 Details
('huam6', '凡
('huam6', '患
('huam6', '梵
('huam6', '漶
('huam6', '犯
('huam6', '范
('huam6', '钒


huan1 Details
('huan1', '欢
('huan1', '还
('huan1', '驩
huan5 Details
('huan5', '鼾
huan7 Details
('huan7', '垾


huang1 Details
('huang1', '坊
('huang1', '封
('huang1', '慌
('huang1', '方
('huang1', '疯
('huang1', '肓
('huang1', '肪
('huang1', '芳
('huang1', '荒
('huang1', '谎
('huang1', '钫
('huang1', '风
huang2 Details
('huang2', '仿
('huang2', '倣
('huang2', '坊
('huang2', '幌
('huang2', '彷
('huang2', '怳
('huang2', '恍
('huang2', '昉
('huang2', '晃
('huang2', '纺
('huang2', '舫
('huang2', '访
('huang2', '髣
huang3 Details
('huang3', '放
huang5 Details
('huang5', '凣
('huang5', '凰
('huang5', '喤
('huang5', '妨
('huang5', '徨
('huang5', '惶
('huang5', '湟
('huang5', '潢
('huang5', '煌
('huang5', '璜
('huang5', '癀
('huang5', '皇
('huang5', '磺
('huang5', '篁
('huang5', '簧
('huang5', '蘅
('huang5', '蝗
('huang5', '蟥
('huang5', '衡
('huang5', '遑
('huang5', '锽
('huang5', '防
('huang5', '隍
('huang5', '鬜
('huang5', '鲂
('huang5', '鳇



hug4 Details
('hug4', '佛
('hug4', '刜
('hug4', '唿
('hug4', '囫
('hug4', '巿
('hug4', '弗
('hug4', '忽
('hug4', '怫
('hug4', '惚
('hug4', '拂
('hug4', '氟
('hug4', '沸
('hug4', '狒
('hug4', '甶
('hug4', '祓
('hug4', '笏
('hug4', '绂
('hug4', '绋
('hug4', '艴
('hug4', '芾
('hug4', '茀
('hug4', '韨
('hug4', '髴
('hug4', '黻
hug8 Details
('hug8', '佛
('hug8', '核



huh4 Details
('huh4', '欻


hui1 Details
('hui1', '啡
('hui1', '妃
('hui1', '婓
('hui1', '徽
('hui1', '扉
('hui1', '挥
('hui1', '斐
('hui1', '晖
('hui1', '灰
('hui1', '绯
('hui1', '翡
('hui1', '腓
('hui1', '菲
('hui1', '蜚
('hui1', '辉
('hui1', '隳
('hui1', '霏
('hui1', '非
('hui1', '飞
('hui1', '騑
('hui1', '麾
hui2 Details
('hui2', '卉
('hui2', '悱
('hui2', '斐
('hui2', '榧
('hui2', '菲
('hui2', '虺
('hui2', '蜚
('hui2', '讳
('hui2', '诽
hui3 Details
('hui3', '剕
('hui3', '喙
('hui3', '废
('hui3', '恚
('hui3', '肺
('hui3', '芾
('hui3', '讳
('hui3', '费
('hui3', '镄
hui5 Details
('hui5', '缶
hui6 Details
('hui6', '僡
('hui6', '彗
('hui6', '惠
('hui6', '慧
('hui6', '憓
('hui6', '槥
('hui6', '篲
('hui6', '蔧
('hui6', '蕙
('hui6', '蟪
('hui6', '轊


huin2 Details
('huin2', '匪
('huin2', '毁
huin3 Details
('huin3', '复
huin5 Details
('huin5', '悬



hung1 Details
('hung1', '分
('hung1', '吩
('hung1', '婚
('hung1', '惛
('hung1', '昏
('hung1', '昬
('hung1', '晕
('hung1', '曛
('hung1', '棻
('hung1', '棼
('hung1', '氛
('hung1', '汾
('hung1', '浑
('hung1', '熏
('hung1', '燻
('hung1', '纷
('hung1', '芬
('hung1', '荤
('hung1', '菸
('hung1', '薰
('hung1', '酚
('hung1', '阍
('hung1', '雰
('hung1', '鼢
hung2 Details
('hung2', '偾
('hung2', '忿
('hung2', '粉
hung3 Details
('hung3', '奋
('hung3', '愤
('hung3', '训
hung5 Details
('hung5', '云
('hung5', '珲
('hung5', '痕
('hung5', '雲
('hung5', '馄
('hung5', '魂
hung6 Details
('hung6', '恽
('hung6', '浑
('hung6', '混
('hung6', '溷
('hung6', '诨
hung7 Details
('hung7', '份
('hung7', '分


huê1 Details
('huê1', '化
('huê1', '华
('huê1', '灰
('huê1', '花
('huê1', '蘤
('huê1', '诙
huê2 Details
('huê2', '伙
('huê2', '火
('huê2', '钬
huê3 Details
('huê3', '化
('huê3', '岁
('huê3', '悔
('huê3', '晦
('huê3', '诲
('huê3', '货
huê5 Details
('huê5', '咊
('huê5', '和
('huê5', '回
('huê5', '洄
('huê5', '茴
('huê5', '蛔
('huê5', '蜖
huê6 Details
('huê6', '会
('huê6', '汇
('huê6', '烩
('huê6', '荟


huêg4 Details
('huêg4', '发
huêg8 Details
('huêg8', '乏
('huêg8', '伐
('huêg8', '垡
('huêg8', '栰
('huêg8', '穴
('huêg8', '筏
('huêg8', '罚
('huêg8', '茓
('huêg8', '阀



huêh4 Details
('huêh4', '血


huên5 Details
('huêh5', '横



huêng1 Details
('huêng1', '欢
('huêng1', '獾
('huêng1', '番
('huêng1', '翻
('huêng1', '貛
('huêng1', '飜
huêng2 Details
('huêng2', '反
('huêng2', '晅
('huêng2', '缓
('huêng2', '返
huêng3 Details
('huêng3', '唤
('huêng3', '奂
('huêng3', '幻
('huêng3', '换
('huêng3', '涣
('huêng3', '焕
('huêng3', '畈
('huêng3', '痪
('huêng3', '贩
huêng5 Details
('huêng5', '圜
('huêng5', '垣
('huêng5', '寰
('huêng5', '擐
('huêng5', '桓
('huêng5', '樊
('huêng5', '洹
('huêng5', '澴
('huêng5', '烦
('huêng5', '环
('huêng5', '繁
('huêng5', '翾
('huêng5', '萑
('huêng5', '还
('huêng5', '镮
('huêng5', '鬟
huêng6 Details
('huêng6', '宦
('huêng6', '豢
('huêng6', '饭


hê1 Details
('hê1', '嘿
hê5 Details
('hê5', '虾
hê6 Details
('hê6', '下
('hê6', '暇
hê7 Details
('hê7', '厦
('hê7', '夏


hêg4 Details
('hêg4', '劾
('hêg4', '核
('hêg4', '纥
('hêg4', '觋
('hêg4', '赩
('hêg4', '阂
('hêg4', '阋
('hêg4', '阖
('hêg4', '黑
hêg8 Details
('hêg8', '乏


hêh4 Details
('hêh4', '吓
('hêh4', '赫


hêng1 Details
('hêng1', '亨
('hêng1', '兴
('hêng1', '匈
('hêng1', '哼
('hêng1', '胷
('hêng1', '胸
('hêng1', '脝
('hêng1', '馨
('hêng1', '鸻
hêng3 Details
('hêng3', '兴
hêng5 Details
('hêng5', '刑
('hêng5', '型
('hêng5', '形
('hêng5', '恒
('hêng5', '王
('hêng5', '硎
('hêng5', '荥
('hêng5', '行
('hêng5', '钘
('hêng5', '铏
('hêng5', '陉
('hêng5', '雄
hêng6 Details
('hêng6', '孕
('hêng6', '杏
('hêng6', '行



i1 Details
('i1', '于
('i1', '伊
('i1', '依
('i1', '吚
('i1', '咿
('i1', '噫
('i1', '嫛
('i1', '洢
('i1', '漪
('i1', '犄
('i1', '猗
('i1', '祎
('i1', '衣
('i1', '迂
('i1', '铱
('i1', '饻
('i1', '鹥
i2 Details
('i2', '倚
('i2', '旖
('i2', '绮
('i2', '迤
i3 Details
('i3', '忆
('i3', '意
('i3', '檍
('i3', '殪
('i3', '澺
('i3', '瘗
('i3', '癔
('i3', '缢
('i3', '肄
('i3', '衣
('i3', '谥
('i3', '镱
('i3', '饐
i5 Details
('i5', '匜
('i5', '咦
('i5', '圯
('i5', '夷
('i5', '姨
('i5', '宧
('i5', '彜
('i5', '彝
('i5', '怡
('i5', '扅
('i5', '栘
('i5', '椸
('i5', '痍
('i5', '眙
('i5', '移
('i5', '簃
('i5', '繄
('i5', '胰
('i5', '荑
('i5', '蛇
('i5', '诒
('i5', '贻
('i5', '跠
('i5', '迤
('i5', '迻
('i5', '饴
i6 Details
('i6', '异
('i6', '懿
('i6', '易
('i6', '裔
i7 Details
('i7', '矣



ia1 Details
('ia1', '呀
ia2 Details
('ia2', '冶
('ia2', '野
ia5 Details
('ia5', '倻
('ia5', '揶
('ia5', '椰
('ia5', '爷
('ia5', '耶
ia7 Details
('ia7', '也
('ia7', '亦
('ia7', '亱
('ia7', '呀
('ia7', '夜
('ia7', '耶



iag4 Details
('iag4', '栎
('iag4', '瀹
('iag4', '烁
('iag4', '烨
('iag4', '约
('iag4', '跃
('iag4', '跞
('iag4', '钥
('iag4', '铄
('iag4', '龠
iag8 Details
('iag8', '药



iah4 Details
('iah4', '溢
('iah4', '益
('iah4', '鹢
iah8 Details
('iah8', '易
('iah8', '驿


ian2 Details
('ian2', '影
ian5 Details
('ian5', '强
('ian5', '营
('ian5', '赢
('ian5', '迎


iang1 Details
('iang1', '央
('iang1', '殃
('iang1', '泱
('iang1', '秧
('iang1', '鞅
iang2 Details
('iang2', '养
('iang2', '氧
iang3 Details
('iang3', '嬿
('iang3', '怏
('iang3', '映
('iang3', '暎
iang5 Details
('iang5', '佯
('iang5', '垟
('iang5', '徉
('iang5', '扬
('iang5', '旸
('iang5', '杨
('iang5', '洋
('iang5', '炀
('iang5', '烊
('iang5', '玚
('iang5', '疡
('iang5', '羊
('iang5', '钖
('iang5', '阳
iang6 Details
('iang6', '恙
('iang6', '漾
('iang6', '痒



ib4 Details
('ib4', '悒
('ib4', '挹
('ib4', '揖
('ib4', '浥
('ib4', '邑


ieu1 Details
('ieu1', '一
('ieu1', '么
('ieu1', '吆
('ieu1', '哟
('ieu1', '夭
('ieu1', '妖
('ieu1', '枵
('ieu1', '要
('ieu1', '邀
('ieu1', '陶
ieu2 Details
('ieu2', '窈
ieu3 Details
('ieu3', '要
ieu5 Details
('ieu5', '徭
('ieu5', '摇
('ieu5', '暚
('ieu5', '珧
('ieu5', '瑶
('ieu5', '繇
('ieu5', '谣
('ieu5', '轺
('ieu5', '遥
('ieu5', '铫
('ieu5', '鳐
('ieu5', '鹞
ieu6 Details
('ieu6', '曜
('ieu6', '燿
('ieu6', '耀



ig4 Details
('ig4', '一
('ig4', '乙
('ig4', '咽
('ig4', '噎
('ig4', '弌
('ig4', '肊
('ig4', '钇
ig8 Details
('ig8', '佚
('ig8', '佾
('ig8', '妷
('ig8', '昳
('ig8', '泆
('ig8', '燚
('ig8', '轶
('ig8', '逸


ih4 Details
('ih4', '浥


im1 Details
('im1', '喑
('im1', '愔
('im1', '淹
('im1', '瘖
('im1', '荫
('im1', '阴
('im1', '音
im2 Details
('im2', '淾
('im2', '饮
im3 Details
('im3', '窨
im5 Details
('im5', '淫
('im5', '滛
('im5', '烎
('im5', '霪


in2 Details
('in2', '以
('in2', '厣
('in2', '圉
('in2', '已
('in2', '椅
('in2', '苡
('in2', '苢
in3 Details
('in3', '嬿
('in3', '燕
('in3', '薏
in5 Details
('in5', '丸
('in5', '圆
in6 Details
('in6', '夗
in7 Details
('in7', '砚
('in7', '院
('in7', '


ing1 Details
('ing1', '咽
('ing1', '因
('ing1', '堙
('ing1', '姻
('ing1', '婣
('ing1', '氤
('ing1', '洇
('ing1', '湮
('ing1', '烟
('ing1', '甄
('ing1', '胭
('ing1', '臙
('ing1', '茵
('ing1', '裀
('ing1', '铟
('ing1', '陻
ing2 Details
('ing2', '引
('ing2', '蚓
('ing2', '隐
ing3 Details
('ing3', '印
('ing3', '应
('ing3', '鮣
ing5 Details
('ing5', '夤
('ing5', '寅
('ing5', '沿
('ing5', '演
('ing5', '萦
('ing5', '铅
ing7 Details
('ing7', '晕


iog4 Details
('iog4', '彧
iog8 Details
('iog8', '唷
('iog8', '峪
('iog8', '慾
('iog8', '欲
('iog8', '浴
('iog8', '淯
('iog8', '育
('iog8', '鬻
('iog8', '鹆



iong1 Details
('iong1', '痈
('iong1', '臃
('iong1', '邕
('iong1', '雍
('iong1', '饔
iong2 Details
('iong2', '俑
('iong2', '勇
('iong2', '壅
('iong2', '永
('iong2', '甬
('iong2', '蛹
('iong2', '踊
iong3 Details
('iong3', '咏
('iong3', '怺
('iong3', '恿
('iong3', '拥
('iong3', '泳
('iong3', '涌
('iong3', '湧
iong5 Details
('iong5', '佣
('iong5', '喁
('iong5', '墉
('iong5', '嬴
('iong5', '容
('iong5', '嵘
('iong5', '庯
('iong5', '庸
('iong5', '慵
('iong5', '榕
('iong5', '溶
('iong5', '滢
('iong5', '潆
('iong5', '瀛
('iong5', '熔
('iong5', '盈
('iong5', '籝
('iong5', '籯
('iong5', '茔
('iong5', '荣
('iong5', '荧
('iong5', '莹
('iong5', '萤
('iong5', '萦
('iong5', '蓉
('iong5', '蓥
('iong5', '蝾
('iong5', '融
('iong5', '镕
('iong5', '镛
('iong5', '颙
('iong5', '鳙
('iong5', '


iu1 Details
('iu1', '优
('iu1', '呦
('iu1', '忧
('iu1', '疣
('iu1', '耰
('iu1', '肬
iu2 Details
('iu2', '卣
('iu2', '友
('iu2', '囮
('iu2', '有
('iu2', '牖
('iu2', '羑
('iu2', '肘
('iu2', '莠
('iu2', '诱
('iu2', '酉
('iu2', '铕
('iu2', '鲔
('iu2', '黝
iu5 Details
('iu5', '尤
('iu5', '揄
('iu5', '柚
('iu5', '油
('iu5', '浟
('iu5', '游
('iu5', '犹
('iu5', '猷
('iu5', '由
('iu5', '繇
('iu5', '莜
('iu5', '莸
('iu5', '蚰
('iu5', '蝣
('iu5', '蝤
('iu5', '遒
('iu5', '邮
('iu5', '酋
('iu5', '釉
('iu5', '铀
('iu5', '髹
('iu5', '鱿
iu6 Details
('iu6', '佑
('iu6', '侑
('iu6', '又
('iu6', '右
('iu6', '囿
('iu6', '宥
('iu6', '祐
('iu6', '贿
iu7 Details
('iu7', '又
('iu7', '有
('iu7', '柚
('iu7', '狖
('iu7', '鼬



iun3 Details
('iun3', '幼
('iun3', '蚴



iê1 Details
('iê1', '哟
('iê1', '腰
('iê1', '鸯
iê2 Details
('iê2', '舀
iê5 Details
('iê5', '姚
('iê5', '摇
('iê5', '窑
iê7 Details
('iê7', '曜



iêg4 Details
('iêg4', '猰



iêh4 Details
('iêh4', '约
iêh8 Details
('iêh8', '药



iên2 Details
('iên2', '养
iên5 Details
('iên5', '扬
('iên5', '杨
('iên5', '洋
('iên5', '溶
('iên5', '炀
('iên5', '烊
('iên5', '熔
('iên5', '羊
('iên5', '蛘
('iên5', '赢
('iên5', '镕
('iên5', '阳
iên7 Details
('iên7', '样
('iên7', '様



iêng1 Details
('iêng1', '嫣
('iêng1', '渊
('iêng1', '焉
('iêng1', '蔫
('iêng1', '鄢
('iêng1', '阏
('iêng1', '鸢
iêng2 Details
('iêng2', '远
iêng3 Details
('iêng3', '燕
iêng5 Details
('iêng5', '媛
('iêng5', '纨
iêng6 Details
('iêng6', '兖
('iêng6', '延
('iêng6', '援
('iêng6', '涎
('iêng6', '爰
('iêng6', '瑗
('iêng6', '筵
('iêng6', '羡
('iêng6', '胤
('iêng6', '蜒
('iêng6', '衍
iêng7 Details
('iêng7', '焉



ka1 Details
('ka1', '脚
('ka1', '骹
ka2 Details
('ka2', '佧
('ka2', '卡
('ka2', '咔
('ka2', '岂
('ka2', '巧
ka3 Details
('ka3', '扣



kab4 Details
('kab4', '刻
('kab4', '匼
('kab4', '嗑
('kab4', '恰
('kab4', '掐
('kab4', '攉
('kab4', '溘
('kab4', '盇
('kab4', '盍
('kab4', '盖
('kab4', '瞌
('kab4', '磕
('kab4', '郃
('kab4', '阖
('kab4', '馌
kab8 Details
('kab8', '榼



kag4 Details
('kag4', '嘎
('kag4', '壳
('kag4', '恪
('kag4', '悫
('kag4', '愙
('kag4', '戛
('kag4', '戞
('kag4', '搉
('kag4', '曲
('kag4', '榷
('kag4', '确
('kag4', '藿
('kag4', '霍
('kag4', '靃



kai1 Details
('kai1', '开
('kai1', '锎
kai2 Details
('kai2', '凯
('kai2', '剀
('kai2', '垲
('kai2', '恺
('kai2', '楷
('kai2', '铠
('kai2', '锲
('kai2', '锴
('kai2', '闿
kai3 Details
('kai3', '忾
('kai3', '慨
('kai3', '暨
('kai3', '概
('kai3', '槩
('kai3', '溉


kam1 Details
('kam1', '勘
('kam1', '堪
('kam1', '嵁
('kam1', '戡
('kam1', '湛
('kam1', '鹐
('kam1', '龛
kam2 Details
('kam2', '坎
('kam2', '嵌
('kam2', '槛
('kam2', '瞰
('kam2', '砍
('kam2', '莰
('kam2', '阚
kam3 Details
('kam3', '冚
('kam3', '墈
('kam3', '磡



kang1 Details
('kang1', '刊
('kang1', '匡
('kang1', '工
('kang1', '康
('kang1', '忼
('kang1', '慷
('kang1', '槺
('kang1', '洭
('kang1', '牵
('kang1', '穅
('kang1', '空
('kang1', '糠
('kang1', '纤
kang3 Details
('kang3', '亢
('kang3', '伉
('kang3', '侃
('kang3', '匟
('kang3', '吭
('kang3', '抗
('kang3', '炕
('kang3', '看
('kang3', '钪
kang5 Details
('kang5', '刊


kao1 Details
('kao1', '尻
('kao1', '抠
('kao1', '薅
('kao1', '阄
kao2 Details
('kao2', '口
('kao2', '拷
('kao2', '栲
('kao2', '槀
('kao2', '槁
('kao2', '烤
('kao2', '考
kao3 Details
('kao3', '叩
('kao3', '哭
('kao3', '寇
('kao3', '扣
('kao3', '敂
('kao3', '铐
('kao3', '靠



ke3 Details
('ke3', '去
ke5 Details
('ke5', '氍
('ke5', '渠
('ke5', '璩
('ke5', '癯
('ke5', '瞿
('ke5', '籧
('ke5', '臞
('ke5', '蕖
('ke5', '蘧
('ke5', '蠼
('ke5', '衢



keg4 Details
('keg4', '乞
('keg4', '仡



keng1 Details
('keng1', '穅
('keng1', '糠
keng2 Details
('keng2', '垦
('keng2', '恳
keng3 Details
('keng3', '劝
('keng3', '囥
('keng3', '邝
keng5 Details
('keng5', '勤
('keng5', '囷
('keng5', '懃
('keng5', '芹



ki1 Details
('ki1', '崎
('ki1', '攲
('ki1', '敧
('ki1', '桤
('ki1', '欺
('ki1', '蹊
ki2 Details
('ki2', '启
('ki2', '屺
('ki2', '杞
('ki2', '棨
('ki2', '芑
('ki2', '起
('ki2', '齿
ki3 Details
('ki3', '亟
('ki3', '器
('ki3', '弃
('ki3', '忾
('ki3', '憇
('ki3', '憩
('ki3', '气
('ki3', '汽
('ki3', '炁
ki5 Details
('ki5', '亓
('ki5', '俟
('ki5', '其
('ki5', '圻
('ki5', '埼
('ki5', '奇
('ki5', '期
('ki5', '歧
('ki5', '沂
('ki5', '淇
('ki5', '琦
('ki5', '琪
('ki5', '璂
('ki5', '祁
('ki5', '祇
('ki5', '祈
('ki5', '祺
('ki5', '綥
('ki5', '綦
('ki5', '耆
('ki5', '芪
('ki5', '蕲
('ki5', '虮
('ki5', '蜞
('ki5', '跂
('ki5', '颀
('ki5', '骐
('ki5', '鬐
('ki5', '鳍
('ki5', '麒
ki7 Details
('ki7', '忌



kia1 Details
('kia1', '奇
('kia1', '家
kia5 Details
('kia5', '擎
('kia5', '蚑
('kia5', '跂
('kia5', '骑
kia6 Details
('kia6', '企
('kia6', '徛
('kia6', '跂



kiag4 Details
('kiag4', '却
('kiag4', '噘
('kiag4', '怯
('kiag4', '攫
('kiag4', '虢
('kiag4', '郄
('kiag4', '镢



kiah4 Details
('kiah4', '郤
('kiah4', '隙



kiang3 Details
('kiang3', '弶
('kiang3', '强
kiang5 Details
('kiang5', '强
('kiang5', '襁
('kiang5', '镪



kib4 Details
('kib4', '吸
('kib4', '圾
('kib4', '岌
('kib4', '歙
('kib4', '泣
('kib4', '笈
('kib4', '级



kih4 Details
('kih4', '屈
('kih4', '缺



kim1 Details
('kim1', '嵚
('kim1', '衾
('kim1', '衿
('kim1', '襟
('kim1', '钦
kim3 Details
('kim3', '揿
kim5 Details
('kim5', '噙
('kim5', '擒
('kim5', '檎
('kim5', '琴
('kim5', '琹
('kim5', '禽
('kim5', '黔



kin5 Details
('kin5', '捦
('kin5', '钳



king1 Details
('king1', '氢
('king1', '轻



kiog4 Details
('kiog4', '克
('kiog4', '可
('kiog4', '曲
('kiog4', '氪


kiong2 Details
('kiong2', '巩
('kiong2', '恐
kiong5 Details
('kiong5', '穷
('kiong5', '筇
('kiong5', '蛩
('kiong5', '跫
('kiong5', '邛



kiu1 Details
('kiu1', '丘
('kiu1', '虬
('kiu1', '蚯
('kiu1', '邱
kiu5 Details
('kiu5', '俅
('kiu5', '巯
('kiu5', '求
('kiu5', '犰
('kiu5', '璆
('kiu5', '裘
('kiu5', '訄
('kiu5', '赇
('kiu5', '逑



kiêg4 Details
('kiêg4', '劂
('kiêg4', '劼
('kiêg4', '厥
('kiêg4', '契
('kiêg4', '孑
('kiêg4', '拮
('kiêg4', '挈
('kiêg4', '揳
('kiêg4', '撅
('kiêg4', '撷
('kiêg4', '橛
('kiêg4', '橜
('kiêg4', '獗
('kiêg4', '矍
('kiêg4', '絜
('kiêg4', '缬
('kiêg4', '蕨
('kiêg4', '诘
('kiêg4', '蹶
('kiêg4', '蹷
('kiêg4', '阙
('kiêg4', '颉
('kiêg4', '黠



kiên1 Details
('kiên1', '腔



kiêng1 Details
('kiêng1', '岍
('kiêng1', '愆
('kiêng1', '搴
('kiêng1', '汧
('kiêng1', '虔
('kiêng1', '骞
kiêng2 Details
('kiêng2', '犬
('kiêng2', '畎
('kiêng2', '缱
('kiêng2', '羟
('kiêng2', '褰
('kiêng2', '謇
('kiêng2', '谴
('kiêng2', '蹇
('kiêng2', '遣
kiêng5 Details
('kiêng5', '乹
('kiêng5', '乾
('kiêng5', '亁
('kiêng5', '干
('kiêng5', '掮



ko1 Details
('ko1', '坷
('ko1', '戈
('ko1', '柯
('ko1', '牁
('ko1', '珂
('ko1', '疴
('ko1', '舸
('ko1', '苛
('ko1', '轲
('ko1', '钶
ko2 Details
('ko2', '可
('ko2', '哿
('ko2', '岢
('ko2', '棵
('ko2', '洘
('ko2', '涸
('ko2', '颗
('ko2', '骒
('ko2', '髁
ko3 Details
('ko3', '锞
('ko3', '靠


kog4 Details
('kog4', '哭
('kog4', '喾
('kog4', '攉
('kog4', '梏
('kog4', '欬
('kog4', '酷
('kog4', '鹄


koh4 Details
('koh4', '咯


koi1 Details
('koi1', '嵠
('koi1', '揩
('koi1', '溪
('koi1', '谿
koi3 Details
('koi3', '契



kong1 Details
('kong1', '崆
('kong1', '硿
('kong1', '空
('kong1', '箜
kong2 Details
('kong2', '倥
('kong2', '孔
kong3 Details
('kong3', '控


kou1 Details
('kou1', '呼
('kou1', '枯
('kou1', '箍
kou2 Details
('kou2', '苦
('kou2', '许
kou3 Details
('kou3', '寇
('kou3', '库
('kou3', '窛
('kou3', '筘
('kou3', '绔
('kou3', '蔻
('kou3', '裤



ku1 Details
('ku1', '丘
('ku1', '刳
('ku1', '区
('ku1', '岖
('ku1', '拘
('ku1', '朐
('ku1', '枢
('ku1', '眍
('ku1', '祛
('ku1', '胠
('ku1', '袪
('ku1', '躯
('ku1', '邱
('ku1', '驱
ku5 Details
('ku5', '跍
ku6 Details
('ku6', '桕
('ku6', '臼
('ku6', '鼩



kua1 Details
('kua1', '侉
('kua1', '咵
('kua1', '垮
('kua1', '夸
('kua1', '挎
('kua1', '跨
kua3 Details
('kua3', '挂
('kua3', '胯
('kua3', '诖



kuag4 Details
('kuag4', '彍
('kuag4', '扩
('kuag4', '阒


kuah4 Details
('kuah4', '阔



kuai3 Details
('kuai3', '快
('kuai3', '筷



kuang1 Details
('kuang1', '劻
('kuang1', '匡
('kuang1', '哐
('kuang1', '恇
('kuang1', '框
('kuang1', '眶
('kuang1', '逛
kuang2 Details
('kuang2', '夼
kuang3 Details
('kuang3', '况
('kuang3', '圹
('kuang3', '扩
('kuang3', '旷
('kuang3', '犷
('kuang3', '矿
('kuang3', '纩
('kuang3', '贶
('kuang3', '邝
kuang5 Details
('kuang5', '狂
('kuang5', '琼
('kuang5', '茕



kug4 Details
('kug4', '倔
('kug4', '屈
('kug4', '矻
('kug4', '窟
('kug4', '诎



kuh4 Details
('kuh4', '窟


kui1 Details
('kui1', '亏
('kui1', '刲
('kui1', '岿
('kui1', '开
kui2 Details
('kui2', '匦
('kui2', '晷
('kui2', '簋
('kui2', '跬
('kui2', '轨
kui3 Details
('kui3', '喟
('kui3', '季
('kui3', '气
kui5 Details
('kui5', '夔
('kui5', '揆
('kui5', '暌
('kui5', '睽
('kui5', '葵
('kui5', '逵
('kui5', '馗
kui6 Details
('kui6', '㱮
('kui6', '匮
('kui6', '愦
('kui6', '愧
('kui6', '溃
('kui6', '篑
('kui6', '聩
('kui6', '蒉
('kui6', '馈



kung1 Details
('kung1', '坤
('kung1', '堃
('kung1', '昆
('kung1', '焜
('kung1', '琨
('kung1', '醌
('kung1', '锟
('kung1', '髠
('kung1', '髡
('kung1', '髨
('kung1', '鲲
('kung1', '鹍
kung2 Details
('kung2', '囷
('kung2', '悃
('kung2', '捆
('kung2', '窘
('kung2', '綑
('kung2', '菌
('kung2', '阃
kung3 Details
('kung3', '困
kung5 Details
('kung5', '惓
('kung5', '拳
('kung5', '羣
('kung5', '群
('kung5', '麇



kuê1 Details
('kuê1', '恢
('kuê1', '悝
('kuê1', '盔
('kuê1', '科
('kuê1', '稞
('kuê1', '蝌
('kuê1', '魁
kuê3 Details
('kuê3', '卦
('kuê3', '课
kuê5 Details
('kuê5', '瘸


kuêh4 Details
('kuêh4', '缺
('kuêh4', '阕
('kuêh4', '阙


kuêng1 Details
('kuêng1', '倾
('kuêng1', '圈
('kuêng1', '宽
('kuêng1', '顷
('kuêng1', '髋
kuêng2 Details
('kuêng2', '倾
('kuêng2', '欵
('kuêng2', '款
('kuêng2', '窾
('kuêng2', '绻
('kuêng2', '顷
kuêng5 Details
('kuêng5', '惓
('kuêng5', '权
('kuêng5', '権
('kuêng5', '蜷
('kuêng5', '颧
('kuêng5', '鬈


kê3 Details
('kê3', '髂
kê5 Details
('kê5', '磲


kêg4 Details
('kêg4', '击
('kêg4', '刻
('kêg4', '劾
('kêg4', '撃
('kêg4', '曲
('kêg4', '粬
('kêg4', '蛐
('kêg4', '麹



kêh4 Details
('kêh4', '喀
('kêh4', '客
('kêh4', '揢



kên1 Details
('kên1', '吭
('kên1', '坑


kêng1 Details
('kêng1', '兢
('kêng1', '卿
('kêng1', '硁
('kêng1', '筐
('kêng1', '銎
kêng2 Details
('kêng2', '啃
('kêng2', '庼
('kêng2', '掯
('kêng2', '檾
('kêng2', '肎
('kêng2', '肯
('kêng2', '苘
('kêng2', '裉
('kêng2', '褃
('kêng2', '龈
kêng3 Details
('kêng3', '庆
('kêng3', '磬
('kêng3', '綮
('kêng3', '罄
('kêng3', '謦
kêng5 Details
('kêng5', '剠
('kêng5', '勍
('kêng5', '坰
('kêng5', '扃
('kêng5', '擎
('kêng5', '檠
('kêng5', '痉
('kêng5', '茎
('kêng5', '鲸
('kêng5', '黥



la1 Details
('la1', '剌
('la1', '啦
('la1', '喇
('la1', '垃
('la1', '拉
('la1', '旯
('la1', '鞡
la5 Details
('la5', '哪
('la5', '朥
('la5', '膋
la6 Details
('la6', '𤰉



lag4 Details
('lag4', '碌
('lag4', '落
lag8 Details
('lag8', '乐
('lag8', '六
('lag8', '力
('lag8', '叻
('lag8', '栗
('lag8', '陆



lah4 Details
('lah4', '邋
lah8 Details
('lah8', '历
('lah8', '拉
('lah8', '猎
('lah8', '瘌
('lah8', '砬
('lah8', '磖
('lah8', '腊
('lah8', '蜡
('lah8', '躐
('lah8', '镴



lai3 Details
('lai3', '徕
('lai3', '来
('lai3', '睐
('lai3', '赉
lai5 Details
('lai5', '来
('lai5', '梨
('lai5', '棃
('lai5', '涞
('lai5', '狸
('lai5', '莱
('lai5', '铼
lai6 Details
('lai6', '内
('lai6', '里
lai7 Details
('lai7', '来



lam2 Details
('lai2', '揽
('lai2', '榄
('lai2', '漤
('lai2', '罱
('lai2', '腩
('lai2', '舰
('lai2', '览
lam5 Details
('lam5', '南
('lam5', '喃
('lam5', '囝
('lam5', '囡
('lam5', '婪
('lam5', '惏
('lam5', '枏
('lam5', '楠
('lam5', '淋
('lam5', '男
('lam5', '蓝
('lam5', '蝻
('lam5', '褴



lang1 Details
('lang1', '啷
lang2 Details
('lang2', '囊
('lang2', '囔
('lang2', '懒
('lang2', '攮
('lang2', '曩
('lang2', '馕
lang3 Details
('lang3', '阆
lang5 Details
('lang5', '兰
('lang5', '嫏
('lang5', '岚
('lang5', '廊
('lang5', '拦
('lang5', '斓
('lang5', '栏
('lang5', '榔
('lang5', '澜
('lang5', '狼
('lang5', '琅
('lang5', '瑯
('lang5', '砻
('lang5', '稂
('lang5', '笼
('lang5', '聋
('lang5', '脓
('lang5', '蜋
('lang5', '螂
('lang5', '谰
('lang5', '踉
('lang5', '郎
('lang5', '锒
('lang5', '镧
('lang5', '阆
('lang5', '阑
('lang5', '难
('lang5', '零
('lang5', '韊
('lang5', '鳞
lang6 Details
('lang6', '卵
('lang6', '崀
('lang6', '朗
('lang6', '浪
('lang6', '烂
('lang6', '烺
('lang6', '莨
('lang6', '蒗
('lang6', '踉
lang7 Details
('lang7', '难



lao1 Details
('lao1', '捞
('lao1', '摎
('lao1', '褛
lao2 Details
('lao2', '佬
('lao2', '姥
('lao2', '栳
('lao2', '篓
('lao2', '老
('lao2', '铑
lao3 Details
('lao3', '涝
('lao3', '溜
('lao3', '耢
lao5 Details
('lao5', '刘
('lao5', '劳
('lao5', '唠
('lao5', '崂
('lao5', '捞
('lao5', '楼
('lao5', '流
('lao5', '溇
('lao5', '潦
('lao5', '留
('lao5', '畱
('lao5', '痨
('lao5', '醪
('lao5', '铹
lao6 Details
('lao6', '老
lao7 Details
('lao7', '漏
('lao7', '瘘
('lao7', '闹



laoh8 Details
('laoh8', '落


le2 Details
('le2', '你
('le2', '妳
('le2', '您
('le2', '汝
le3 Details
('le3', '鑢
le5 Details
('le5', '劳
('le5', '榈
('le5', '闾
('le5', '驴
le6 Details
('le6', '侣
('le6', '吕
('le6', '滤
('le6', '窭
('le6', '虑
('le6', '铝


li2 Details
('li2', '哩
('li2', '娌
('li2', '履
('li2', '旅
('li2', '李
('li2', '浬
('li2', '澧
('li2', '理
('li2', '礼
('li2', '膂
('li2', '蠡
('li2', '逦
('li2', '醴
('li2', '里
('li2', '锂
('li2', '鲤
('li2', '鳢
li3 Details
('li3', '捸
li5 Details
('li5', '丽
('li5', '俚
('li5', '劙
('li5', '厘
('li5', '喱
('li5', '嫠
('li5', '漓
('li5', '牦
('li5', '狸
('li5', '琍
('li5', '璃
('li5', '离
('li5', '篱
('li5', '缡
('li5', '罹
('li5', '藜
('li5', '螭
('li5', '醨
('li5', '骊
('li5', '魑
('li5', '鹂
('li5', '黎
('li5', '黧
li6 Details
('li6', '䖽
('li6', '丽
('li6', '俪
('li6', '利
('li6', '励
('li6', '厉
('li6', '唳
('li6', '戾
('li6', '捩
('li6', '涖
('li6', '疠
('li6', '痢
('li6', '砺
('li6', '粝
('li6', '荔
('li6', '莅
('li6', '莉
('li6', '蛎
('li6', '蜊
('li6', '詈
('li6', '鬁
('li6', '鲡
li7 Details
('li7', '例
('li7', '吏
('li7', '哩



liag8 Details
('liag8', '傈
('liag8', '撂
('liag8', '略
('liag8', '畧



liah8 Details
('liah8', '掠


liang2 Details
('liang2', '两
('liang2', '俩
('liang2', '辆
('liang2', '魉
liang5 Details
('liang5', '凉
('liang5', '怜
('liang5', '梁
('liang5', '樑
('liang5', '粱
('liang5', '良
('liang5', '量
liang6 Details
('liang6', '亮
('liang6', '喨
('liang6', '晾
('liang6', '蔺
('liang6', '谅
('liang6', '躏
('liang6', '量



lib8 Details
('lib8', '立


lih8 Details
('lih8', '咧
('lih8', '裂



lim2 Details
('lim2', '凛
('lim2', '廪
('lim2', '懔
lim3 Details
('lim3', '檩
lim5 Details
('lim5', '临
('lim5', '啉
('lim5', '林
('lim5', '淋
('lim5', '琳
('lim5', '霖



ling2 Details
('ling2', '辇
ling5 Details
('ling5', '嶙
('ling5', '燐
('ling5', '璘
('ling5', '磷
('ling5', '粼
('ling5', '联
('ling5', '辚
('ling5', '遴
('ling5', '邻
('ling5', '鲢
('ling5', '鳞
('ling5', '麐
('ling5', '麟



liu1 Details
('liu1', '溜
('liu1', '熘
('liu1', '鸠
liu2 Details
('liu2', '㧕
('liu2', '柳
('liu2', '桺
('liu2', '绺
liu3 Details
('liu3', '溜
('liu3', '遛
('liu3', '馏
('liu3', '鹨
liu5 Details
('liu5', '六
('liu5', '旒
('liu5', '榴
('liu5', '流
('liu5', '浏
('liu5', '琉
('liu5', '瑠
('liu5', '留
('liu5', '畱
('liu5', '瘤
('liu5', '癅
('liu5', '硫
('liu5', '鎏
('liu5', '镏
('liu5', '镠
('liu5', '骝
('liu5', '𨻧
liu7 Details
('liu7', '摎
('liu7', '籀



liêg8 Details
('liêg8', '䴕
('liêg8', '冽
('liêg8', '列
('liêg8', '栗
('liêg8', '洌
('liêg8', '溧
('liêg8', '烈
('liêg8', '篥
('liêg8', '趔
('liêg8', '鬣



liêm1 Details
('liêm1', '粘
liêm5 Details
('liêm5', '镰



liêng2 Details
('liêng2', '脸
liêng5 Details
('liêng5', '怜
('liêng5', '涟
('liêng5', '琏
('liêng5', '联
('liêng5', '莲
('liêng5', '裢
('liêng5', '连
('liêng5', '链
('liêng5', '鲢
liêng6 Details
('liêng6', '吝
('liêng6', '恡
liêng7 Details
('liêng7', '楝
('liêng7', '炼
('liêng7', '练
('liêng7', '链



lo1 Details
('lo1', '啰
('lo1', '窠
lo2 Details
('lo2', '倮
('lo2', '恼
('lo2', '栳
('lo2', '潦
('lo2', '脑
('lo2', '蓏
('lo2', '裸
('lo2', '裹
('lo2', '躶
('lo2', '颗
lo5 Details
('lo5', '漯
('lo5', '牢
('lo5', '猡
('lo5', '瘰
('lo5', '箩
('lo5', '罗
('lo5', '脶
('lo5', '萝
('lo5', '螺
('lo5', '蠃
('lo5', '逻
('lo5', '醪
('lo5', '锣
('lo5', '骡
lo7 Details
('lo7', '咯
('lo7', '喽



log4 Details
('log4', '摝
log8 Details
('log8', '剹
('log8', '录
('log8', '戮
('log8', '朒
('log8', '泺
('log8', '洛
('log8', '渌
('log8', '漉
('log8', '烙
('log8', '珞
('log8', '甪
('log8', '硌
('log8', '碌
('log8', '磊
('log8', '禄
('log8', '箓
('log8', '簏
('log8', '络
('log8', '貉
('log8', '逯
('log8', '酪
('log8', '陆
('log8', '雒
('log8', '饹
('log8', '骆
('log8', '骼
('log8', '麓



loh8 Details
('loh8', '摞
('loh8', '荦
('loh8', '落
('loh8', '骆



loi2 Details
('loi2', '礼
loi5 Details
('loi5', '犁
('loi5', '犂
('loi5', '黎
loi7 Details
('loi7', '篱



loih8 Details
('loih8', '笠



long1 Details
('long1', '癃
long2 Details
('long2', '垄
('long2', '拢
('long2', '笼
long5 Details
('long5', '侬
('long5', '农
('long5', '哝
('long5', '囊
('long5', '昽
('long5', '泷
('long5', '浓
('long5', '珑
('long5', '癃
('long5', '窿
('long5', '胧
('long5', '脓
('long5', '茏
('long5', '隆
long6 Details
('long6', '弄



lou2 Details
('lou2', '卤
('lou2', '恼
('lou2', '惱
('lou2', '搂
('lou2', '橹
('lou2', '鹵
lou5 Details
('lou5', '卢
('lou5', '庐
('lou5', '炉
('lou5', '耧
('lou5', '胪
('lou5', '鲈
('lou5', '鸬
lou6 Details
('lou6', '卤
('lou6', '陋
('lou6', '鹵
lou7 Details
('lou7', '路
('lou7', '露



lu1 Details
('lu1', '夵
lu2 Details
('lu2', '偻
('lu2', '噜
('lu2', '屡
('lu2', '掳
('lu2', '橹
('lu2', '氇
('lu2', '稆
('lu2', '缕
('lu2', '虏
('lu2', '褛
('lu2', '镂
('lu2', '镥
('lu2', '鲁
lu5 Details
('lu5', '偻
('lu5', '卢
('lu5', '垆
('lu5', '娄
('lu5', '嵝
('lu5', '庐
('lu5', '栌
('lu5', '泸
('lu5', '胪
('lu5', '舻
('lu5', '芦
('lu5', '蒌
('lu5', '蝼
('lu5', '轳
('lu5', '颅
('lu5', '髅
('lu5', '鸬
lu6 Details
('lu6', '潞
('lu6', '璐
('lu6', '赂
('lu6', '辂
('lu6', '鹭



lua5 Details
('lua5', '箩
lua7 Details
('lua7', '赖



luah4 Details
('luah4', '烙
('luah4', '辢
('luah4', '辣
luah8 Details
('luah8', '擸
('luah8', '辢
('luah8', '辣
('luah8', '阅



lug4 Details
('lug4', '脱
lug8 Details
('lug8', '律
('lug8', '捋
('lug8', '燏
('lug8', '率
('lug8', '矞
('lug8', '聿
('lug8', '葎
('lug8', '遹
('lug8', '鹬



lui2 Details
('lui2', '亝
('lui2', '儡
('lui2', '垒
('lui2', '嫘
('lui2', '磊
('lui2', '累
('lui2', '耒
('lui2', '蕊
('lui2', '蕋
('lui2', '蕾
('lui2', '诔
lui5 Details
('lui5', '擂
('lui5', '檑
('lui5', '礌
('lui5', '礧
('lui5', '缧
('lui5', '罍
('lui5', '羸
('lui5', '蕾
('lui5', '镭
('lui5', '雷
('lui5', '靁
lui6 Details
('lui6', '傫
('lui6', '儽
('lui6', '泪
('lui6', '涙
('lui6', '累
lui7 Details
('lui7', '类



lung2 Details
('lung2', '忍
lung3 Details
('lung3', '嫩
lung5 Details
('lung5', '仑
('lung5', '伦
('lung5', '囵
('lung5', '抡
('lung5', '沦
('lung5', '纶
('lung5', '轮
lung6 Details
('lung6', '论



luêg4 Details
('luêg4', '劣
('luêg4', '埒
('luêg4', '捋
('luêg4', '酹
('luêg4', '阅



luêng2 Details
('luêng2', '暅
('luêng2', '暖
('luêng2', '煖
luêng3 Details
('luêng3', '恋
luêng5 Details
('luêng5', '娈
('luêng5', '孪
('luêng5', '峦
('luêng5', '挛
('luêng5', '栾
('luêng5', '滦
('luêng5', '脔
('luêng5', '脟
('luêng5', '銮
('luêng5', '鸾
luêng6 Details
('luêng6', '乱



lê7 Details
('lê7', '嘞



lêg8 Details
('lêg8', '仂
('lêg8', '勒
('lêg8', '氯
('lêg8', '玏
('lêg8', '疬
('lêg8', '簕
('lêg8', '绿
('lêg8', '肋
('lêg8', '陆
('lêg8', '鳓


lêh4 Details
('lêh4', '叻
lêh8 Details
('lêh8', '历
('lêh8', '栎
('lêh8', '砾
('lêh8', '鬲



lêng1 Details
('lêng1', '铃
('lêng1', '靓
lêng2 Details
('lêng2', '垄
('lêng2', '搑
('lêng2', '撵
('lêng2', '陇
lêng5 Details
('lêng5', '伶
('lêng5', '凌
('lêng5', '另
('lêng5', '咙
('lêng5', '咛
('lêng5', '囹
('lêng5', '塄
('lêng5', '宁
('lêng5', '寍
('lêng5', '崚
('lêng5', '愣
('lêng5', '拎
('lêng5', '拧
('lêng5', '柃
('lêng5', '柠
('lêng5', '栊
('lêng5', '棂
('lêng5', '棱
('lêng5', '楞
('lêng5', '泞
('lêng5', '泠
('lêng5', '灵
('lêng5', '狞
('lêng5', '玲
('lêng5', '瓴
('lêng5', '睖
('lêng5', '绫
('lêng5', '羚
('lêng5', '翎
('lêng5', '聆
('lêng5', '聍
('lêng5', '能
('lêng5', '舲
('lêng5', '苓
('lêng5', '菱
('lêng5', '蓤
('lêng5', '薐
('lêng5', '蛉
('lêng5', '酃
('lêng5', '陵
('lêng5', '隆
('lêng5', '零
('lêng5', '鲮
('lêng5', '鸰
('lêng5', '龄
('lêng5', '龙
lêng6 Details
('lêng6', '令
('lêng6', '佞
lêng7 Details
('lêng7', '堎



m2 Details
('m2', '姆
('m2', '姥
('m2', '拇
('m2', '母
m6 Details
('m6', '呣
('m6', '唔
('m6', '毋
m7 Details
('m7', '呣

ma1 Details
('ma1', '吗
('ma1', '妈
('ma1', '嫲
('ma1', '嬷
('ma1', '孖
ma2 Details
('ma2', '吗
('ma2', '妈
('ma2', '嫲
('ma2', '犸
('ma2', '玛
('ma2', '码
('ma2', '蚂
('ma2', '马
ma5 Details
('ma5', '妈
ma7 Details
('ma7', '嘛
('ma7', '嚜



mag4 Details
('mag4', '蔑
mag8 Details
('mag8', '目
('mag8', '钼



mai3 Details
('mai3', '勿
('mai3', '嫑
mai5 Details
('mai5', '埋
('mai5', '霾
mai6 Details
('mai6', '劢
('mai6', '迈



mang2 Details
('mang2', '挽
('mang2', '莽
('mang2', '蟒
('mang2', '蠓
mang5 Details
('mang5', '忙
('mang5', '氓
('mang5', '牤
('mang5', '牻
('mang5', '盲
('mang5', '硭
('mang5', '芒
('mang5', '茫
('mang5', '虻
('mang5', '蛮
('mang5', '蝱
('mang5', '邙
('mang5', '铓
('mang5', '闽
mang6 Details
('mang6', '幕
('mang6', '曼
('mang6', '网
mang7 Details
('mang7', '慢
('mang7', '梦
('mang7', '缓



mao1 Details
('mao1', '猫
mao3 Details
('mao3', '眊
('mao3', '耄
mao5 Details
('mao5', '旄
('mao5', '毛
('mao5', '牦
('mao5', '犛
('mao5', '矛
('mao5', '茅
('mao5', '茆
('mao5', '蟊
('mao5', '酕
('mao5', '鍪
('mao5', '髦
mao6 Details
('mao6', '冐
('mao6', '冒
('mao6', '瑁
('mao6', '皃
('mao6', '貌



mi1 Details
('mi1', '乜
('mi1', '咪
('mi1', '眯
('mi1', '瞇
('mi1', '臱
mi2 Details
('mi2', '籹
('mi2', '芈
('mi2', '靡
mi5 Details
('mi5', '劘
('mi5', '湄
('mi5', '眉
('mi5', '眯
('mi5', '糜
('mi5', '縻
('mi5', '蘪
('mi5', '蘼
('mi5', '迷
('mi5', '醚
('mi5', '麋
mi6 Details
('mi6', '媚
('mi6', '袂
('mi6', '谜



mian5 Details
('mian5', '名
mian7 Details
('mian7', '命



mig4 Details
('mig4', '乜
mig8 Details
('mig8', '嘧
('mig8', '宓
('mig8', '密
('mig8', '幂
('mig8', '汨
('mig8', '灭
('mig8', '蔑
('mig8', '蜜
('mig8', '蠛
('mig8', '觅
('mig8', '谧
('mig8', '默



min5 Details
('min5', '棉
('min5', '绵
min7 Details
('min7', '面
('min7', '靣
('min7', '麵



ming2 Details
('ming2', '免
('ming2', '甭
ming5 Details
('ming5', '岷
('ming5', '抿
('ming5', '旻
('ming5', '民
('ming5', '氓
('ming5', '泯
('ming5', '湣
('ming5', '珉
('ming5', '眠
('ming5', '缗
('ming5', '苠
ming7 Details
('ming7', '面
('ming7', '靣



miêng2 Details
('miêng2', '丏
('miêng2', '偭
('miêng2', '免
('miêng2', '冕
('miêng2', '勉
('miêng2', '娩
('miêng2', '悯
('miêng2', '愍
('miêng2', '敏
('miêng2', '沔
('miêng2', '渑
('miêng2', '湎
('miêng2', '湣
('miêng2', '眄
('miêng2', '缅
('miêng2', '腼
('miêng2', '闵
('miêng2', '鳘
('miêng2', '黾
miêng5 Details
('miêng5', '绵



mo1 Details
('mo1', '嬷
('mo1', '馍
mo2 Details
('mo2', '孬
mo5 Details
('mo5', '嫫
('mo5', '摩
('mo5', '摸
('mo5', '摹
('mo5', '模
('mo5', '毛
('mo5', '蘑
('mo5', '蟆
('mo5', '蟇
('mo5', '谟
('mo5', '魔
mo6 Details
('mo6', '募
('mo6', '墓
('mo6', '幕
('mo6', '幙
('mo6', '慕
('mo6', '暮
mo7 Details
('mo7', '么
('mo7', '望
('mo7', '朢
('mo7', '礳
('mo7', '耱



mog8 Details
('mog8', '万
('mog8', '寞
('mog8', '木
('mog8', '殁
('mog8', '沐
('mog8', '没
('mog8', '漠
('mog8', '牧
('mog8', '疫
('mog8', '睦
('mog8', '穆
('mog8', '缪
('mog8', '苜
('mog8', '莫
('mog8', '貘
('mog8', '鄚


moh4 Details
('moh4', '么
('moh4', '仫
moh8 Details
('moh8', '漠
('moh8', '瘼
('moh8', '膜


mong2 Details
('mong2', '懵
('mong2', '晚
('mong2', '某
mong3 Details
('mong3', '贸
mong5 Details
('mong5', '幪
('mong5', '摸
('mong5', '曚
('mong5', '朦
('mong5', '檬
('mong5', '獴
('mong5', '瞢
('mong5', '礞
('mong5', '艨
('mong5', '芒
('mong5', '蒙
('mong5', '蠓
('mong5', '谋
mong6 Details
('mong6', '舞
('mong6', '茂



mou3 Details
('mou3', '瞀
mou5 Details
('mou5', '侔
('mou5', '哞
('mou5', '幪
('mou5', '毪
('mou5', '牟
('mou5', '眸
('mou5', '蒙
('mou5', '蛑
('mou5', '谋
mou6 Details
('mou6', '懋
('mou6', '瞀
('mou6', '茂
('mou6', '袤



mua5 Details
('mua5', '痲
('mua5', '麻



muan2 Details
('muan2', '满
('muan2', '螨
muan5 Details
('muan5', '瞒
('muan5', '颟
('muan5', '鳗



mug4 Details
('mug4', '刎
mug8 Details
('mug8', '没



mui2 Details
('mui2', '娓
('mui2', '美
('mui2', '镁
mui5 Details
('mui5', '微
('mui5', '溦
('mui5', '薇



mung2 Details
('mung2', '晚
mung5 Details
('mung5', '亹
('mung5', '们
('mung5', '扪
('mung5', '钔
('mung5', '门
mung7 Details
('mung7', '璺
('mung7', '问



muê2 Details
('muê2', '每
muê5 Details
('muê5', '糜
('muê5', '蘪
muê6 Details
('muê6', '妹
('muê6', '寐
('muê6', '昧
('muê6', '浼
('muê6', '鬽
('muê6', '魅



muêg8 Details
('muêg8', '妺
('muêg8', '末
('muêg8', '眜
('muêg8', '秣
('muêg8', '茉
('muêg8', '靺



muêh8 Details
('muêh8', '物


mê5 Details
('mê5', '夜
mê7 Details
('mê7', '骂



mêg8 Details
('mêg8', '蓦
('mêg8', '貊
('mêg8', '陌



mêh4 Details
('mêh4', '咩
('mêh4', '哶
mêh8 Details
('mêh8', '脉



mên2 Details
('mên2', '蜢
mên5 Details
('mên5', '冥
('mên5', '暝
('mên5', '盲
('mên5', '芒



mêng2 Details
('mêng2', '猛
('mêng2', '皿
('mêng2', '艋
('mêng2', '蜢
('mêng2', '锰
mêng3 Details
('mêng3', '勐
mêng5 Details
('mêng5', '冥
('mêng5', '名
('mêng5', '明
('mêng5', '暝
('mêng5', '洺
('mêng5', '溟
('mêng5', '甍
('mêng5', '盟
('mêng5', '盲
('mêng5', '瞑
('mêng5', '茗
('mêng5', '萌
('mêng5', '螟
('mêng5', '酩
('mêng5', '铭
('mêng5', '鸣
mêng6 Details
('mêng6', '命
('mêng6', '孟



na1 Details
('na1', '南
na2 Details
('na2', '哪
('na2', '拿
('na2', '榄
('na2', '那
('na2', '镎
na5 Details
('na5', '哪
('na5', '林
('na5', '篮
('na5', '蓝
na7 Details
('na7', '哪
('na7', '喏



nab8 Details
('nab8', '呐
('nab8', '喏
('nab8', '捺
('nab8', '掿
('nab8', '搦
('nab8', '朒
('nab8', '纳
('nab8', '肭
('nab8', '衂
('nab8', '衄
('nab8', '衲
('nab8', '讷
('nab8', '诺
('nab8', '钠
('nab8', '锘



nah4 Details
('nah4', '垃
('nah4', '拉



nai2 Details
('nai2', '乃
('nai2', '奶
('nai2', '嬭
nai6 Details
('nai6', '乃
('nai6', '奈
('nai6', '廼
('nai6', '捺
('nai6', '柰
('nai6', '氖
('nai6', '濑
('nai6', '癞
('nai6', '籁
('nai6', '耐
('nai6', '萘
('nai6', '褦
('nai6', '赖
('nai6', '鼐



nang2 Details
('nang2', '俺
('nang2', '赧
nang5 Details
('nang5', '人
('nang5', '侬
('nang5', '齉
nang7 Details
('nang7', '人



nao1 Details
('nao1', '孬
('nao1', '浇
nao2 Details
('nao2', '恼
('nao2', '惱
('nao2', '瑙
('nao2', '脑
nao5 Details
('nao5', '呶
('nao5', '峱
('nao5', '巙
('nao5', '挠
('nao5', '猱
('nao5', '獿
('nao5', '硇
('nao5', '蛲
('nao5', '铙
nao6 Details
('nao6', '弩
('nao6', '扭
('nao6', '闹
nao7 Details
('nao7', '槈
('nao7', '耨
('nao7', '闹



neng2 Details
('neng2', '女
('neng2', '软
('neng2', '钕
neng3 Details
('neng3', '钻
neng5 Details
('neng5', '瓤
('neng5', '郎
neng6 Details
('neng6', '卵
neng7 Details
('neng7', '浪



ni1 Details
('ni1', '呢
('ni1', '奶
ni2 Details
('ni2', '女
('ni2', '弥
('ni2', '弭
('ni2', '染
('ni2', '猕
('ni2', '祢
('ni2', '迩
ni3 Details
('ni3', '泥
ni5 Details
('ni5', '呢
('ni5', '坭
('ni5', '妮
('ni5', '尼
('ni5', '年
('ni5', '怩
('ni5', '旎
('ni5', '泥
('ni5', '艿
('ni5', '铌
ni6 Details
('ni6', '奶
('ni6', '嬭
('ni6', '腻



nian2 Details
('nian2', '岭
('nian2', '领
nian4 Details
('nian4', '向



niang5 Details
('niang5', '娘
('niang5', '孃



nih4 Details
('nih4', '痆



niu2 Details
('niu2', '妞
('niu2', '忸
('niu2', '扭
('niu2', '狃
('niu2', '纽
('niu2', '钮
niu5 Details
('niu5', '缪
niu6 Details
('niu6', '缪
('niu6', '谬



niên2 Details
('niên2', '唡
niên5 Details
('niên5', '娘
('niên5', '孃
('niên5', '梁
('niên5', '樑
('niên5', '粮
('niên5', '粱
('niên5', '量
niên7 Details
('niên7', '让



no2 Details
('no2', '弩
no3 Details
('no3', '努
('no3', '怒
('no3', '懦
('no3', '砮
('no3', '穤
('no3', '糯
('no3', '驽
no5 Details
('no5', '傩
('no5', '娜
('no5', '挪
no6 Details
('no6', '两
('no6', '二
('no6', '弍
('no6', '貮
('no6', '贰
no7 Details
('no7', '怒
('no7', '槈
('no7', '耨



noin5 Details
('noin5', '縺
('noin5', '莲
noin7 Details
('noin7', '楝


nou1 Details
('nou1', '奴
('nou1', '孥
nou5 Details
('nou5', '奴
('nou5', '孥



nuan3 Details
('nuan3', '僆
nuan6 Details
('nuan6', '囒
nuan7 Details
('nuan7', '烂



nui2 Details
('nui2', '馁



nêg4 Details
('nêg4', '蹃
nêg8 Details
('nêg8', '匿
('nêg8', '恧
('nêg8', '慝
('nêg8', '搦
('nêg8', '昵
('nêg8', '暱
('nêg8', '溺
('nêg8', '肉
('nêg8', '衂
('nêg8', '衄



nên2 Details
('nên2', '冷



ng1 Details
('ng1', '奀
('ng1', '恩
('ng1', '秧
ng2 Details
('ng2', '尹
('ng2', '箢
ng5 Details
('ng5', '嗯
('ng5', '橼
('ng5', '磺
('ng5', '隍
('ng5', '黄
ng6 Details
('ng6', '嗯
ng7 Details
('ng7', '嗯



ngag8 Details
('ngag8', '噩
('ngag8', '岳
('ngag8', '腭
('ngag8', '萼
('ngag8', '蕚
('ngag8', '谔
('ngag8', '鄂
('ngag8', '锷
('ngag8', '颚
('ngag8', '鳄
('ngag8', '鹗



ngai5 Details
('ngai5', '呆
('ngai5', '崕
('ngai5', '崖
('ngai5', '捱
('ngai5', '涯
('ngai5', '皑
('ngai5', '睚
('ngai5', '騃
ngai6 Details
('ngai6', '刈
('ngai6', '岸
('ngai6', '砹
('ngai6', '艾



ngam1 Details
('ngam1', '啱
ngam5 Details
('ngam5', '岩
('ngam5', '巖
('ngam5', '癌



ngang1 Details
('ngang1', '昂
ngang2 Details
('ngang2', '眼
ngang3 Details
('ngang3', '唁
ngang5 Details
('ngang5', '元
('ngang5', '凝
('ngang5', '言
('ngang5', '顏
('ngang5', '颜
ngang6 Details
('ngang6', '彦
('ngang6', '犴
('ngang6', '谚
('ngang6', '赝
('ngang6', '雁



ngao1 Details
('ngao1', '嚣
('ngao1', '嚻
('ngao1', '囂
ngao5 Details
('ngao5', '嗷
('ngao5', '崤
('ngao5', '嶅
('ngao5', '廒
('ngao5', '敖
('ngao5', '洨
('ngao5', '淆
('ngao5', '熬
('ngao5', '爻
('ngao5', '獒
('ngao5', '翱
('ngao5', '聱
('ngao5', '肴
('ngao5', '螯
('ngao5', '遨
('ngao5', '鳌
ngao6 Details
('ngao6', '傲
('ngao6', '奡
('ngao6', '鏊
('ngao6', '骜



ngeg4 Details
('ngeg4', '吃
('ngeg4', '喫
('ngeg4', '圪
('ngeg4', '屹
('ngeg4', '疙
('ngeg4', '讫
('ngeg4', '迄



ngeng5 Details
('ngeng5', '垠
('ngeng5', '狺
('ngeng5', '鄞
('ngeng5', '银
('ngeng5', '靳
('ngeng5', '龈



ngi2 Details
('ngi2', '儗
('ngi2', '拟
('ngi2', '舣
('ngi2', '议
ngi3 Details
('ngi3', '呓
('ngi3', '睨
('ngi3', '谊
ngi5 Details
('ngi5', '仪
('ngi5', '倪
('ngi5', '宜
('ngi5', '毅
('ngi5', '猊
('ngi5', '羿
('ngi5', '輗
('ngi5', '霓
('ngi5', '鲵
('ngi5', '麑
ngi6 Details
('ngi6', '乂
('ngi6', '义
('ngi6', '刈
('ngi6', '劓



ngia2 Details
('ngia2', '美
('ngia2', '雅



ngiag8 Details
('ngiag8', '疟
('ngiag8', '虐
('ngiag8', '谑
('ngiag8', '镍



ngiang2 Details
('ngiang2', '仰
ngiang3 Details
('ngiang3', '齴



ngim5 Details
('ngim5', '吟
('ngim5', '唫
('ngim5', '岑
('ngim5', '崟
('ngim5', '涔
('ngim5', '芩
('ngim5', '黔



ngiêg8 Details
('ngiêg8', '臬



ngiêng2 Details
('ngiêng2', '研
ngiêng3 Details
('ngiêng3', '愿
('ngiêng3', '慭
('ngiêng3', '憖
('ngiêng3', '瘾
ngiêng5 Details
('ngiêng5', '凝
('ngiêng5', '妍
('ngiêng5', '姸
('ngiêng5', '研
('ngiêng5', '聍
('ngiêng5', '迎



ngo2 Details
('ngo2', '俣
('ngo2', '我
ngo5 Details
('ngo5', '俄
('ngo5', '吾
('ngo5', '哦
('ngo5', '喁
('ngo5', '娥
('ngo5', '峨
('ngo5', '峩
('ngo5', '嵎
('ngo5', '愚
('ngo5', '梧
('ngo5', '硪
('ngo5', '禺
('ngo5', '莪
('ngo5', '虞
('ngo5', '蛾
('ngo5', '锇
('ngo5', '隅
ngo6 Details
('ngo6', '寓
('ngo6', '寤
('ngo6', '悟
('ngo6', '晤
('ngo6', '遇



ngog8 Details
('ngog8', '愕



ngoh8 Details
('ngoh8', '愕



ngoin2 Details
('ngoin2', '研



ngou2 Details
('ngou2', '五
('ngou2', '仵
('ngou2', '伍
('ngou2', '偶
('ngou2', '午
('ngou2', '忤
('ngou2', '牾
('ngou2', '牿
('ngou2', '耦
('ngou2', '藕
('ngou2', '迕
ngou6 Details
('ngou6', '五
('ngou6', '伍



nguin5 Details
('nguin5', '危
('nguin5', '嵬
('nguin5', '巍
('nguin5', '隗
nguin6 Details
('nguin6', '伪
('nguin6', '诡



nguêng2 Details
('nguêng2', '妧
('nguêng2', '朊
('nguêng2', '玩
('nguêng2', '阮
('nguêng2', '顽
nguêng5 Details
('nguêng5', '元
('nguêng5', '刓
('nguêng5', '原
('nguêng5', '塬
('nguêng5', '嫄
('nguêng5', '沅
('nguêng5', '源
('nguêng5', '羱
('nguêng5', '芫
('nguêng5', '螈
('nguêng5', '顏
('nguêng5', '颜
('nguêng5', '鼋
nguêng6 Details
('nguêng6', '愿


ngên6 Details
('ngên6', '硬



o1 Details
('o1', '倭
('o1', '呵
('o1', '喔
('o1', '噢
('o1', '娲
('o1', '婀
('o1', '屙
('o1', '涡
('o1', '濄
('o1', '窝
('o1', '莴
('o1', '蒿
('o1', '蜗
('o1', '踒
('o1', '鏖
('o1', '阿
o2 Details
('o2', '啊
('o2', '袄
o3 Details
('o3', '奥
('o3', '懊
('o3', '澳
o5 Details
('o5', '荷
('o5', '菏
('o5', '蚝
('o5', '蠔
o6 Details
('o6', '卧
('o6', '哦
('o6', '啊
('o6', '荷
o7 Details
('o7', '哦
('o7', '啊



og4 Details
('og4', '偓
('og4', '喔
('og4', '垩
('og4', '屋
('og4', '幄
('og4', '握
('og4', '沃
('og4', '渥
('og4', '鋈
('og4', '龌



oh4 Details
('oh4', '呃
('oh4', '呝
('oh4', '恶
oh8 Details
('oh8', '学



oi1 Details
('oi1', '挨
oi2 Details
('oi2', '倭
('oi2', '矮
oi5 Details
('oi5', '鞋
('oi5', '鞵
oi6 Details
('oi6', '会


oih8 Details
('oih8', '狭



oin5 Details
('oin8', '闲



ong1 Details
('ong1', '嗡
('ong1', '翁
('ong1', '蓊
('ong1', '鹟
ong2 Details
('ong2', '滃
ong3 Details
('ong3', '盎
('ong3', '螉
('ong3', '齆
ong6 Details
('ong6', '拥


ou1 Details
('ou1', '乌
('ou1', '钨
('ou1', '鸥
ou5 Details
('ou5', '湖
('ou5', '箶
('ou5', '胡
ou7 Details
('ou7', '芋



pa1 Details
('pa1', '抛
('pa1', '脬
('pa1', '趴
pa6 Details
('pa6', '泡
('pa6', '疱



pag4 Details
('pag4', '伏
('pag4', '博
('pag4', '搏
('pag4', '趴
('pag4', '馎
pag8 Details
('pag8', '僰
('pag8', '暴
('pag8', '曝
('pag8', '瀑
('pag8', '雹



pah4 Details
('pah4', '啪
('pah4', '打
('pah4', '拍



pai2 Details
('pai2', '呸
('pai2', '痞
pai3 Details
('pai3', '旆
('pai3', '沛
('pai3', '派
('pai3', '湃
('pai3', '霈
pai5 Details
('pai5', '排



pan3 Details
('pan3', '冇
('pan3', '奅
('pan3', '怕



pang1 Details
('pang1', '攀
('pang1', '芳
('pang1', '蜂
('pang1', '香
pang2 Details
('pang2', '纺
pang3 Details
('pang3', '盼
('pang3', '袢
('pang3', '襻
('pang3', '鋬
pang5 Details
('pang5', '傍
('pang5', '帆
('pang5', '庞
('pang5', '彭
('pang5', '彷
('pang5', '旁
('pang5', '滂
('pang5', '磅
('pang5', '篷
('pang5', '膀
('pang5', '航
('pang5', '蒡
('pang5', '螃
('pang5', '逄
('pang5', '霶
('pang5', '鳑
pang7 Details
('pang7', '缝



pao1 Details
('pao1', '刨
('pao1', '抛
('pao1', '泡
('pao1', '脬
('pao1', '褒
('pao1', '铇
pao2 Details
('pao2', '跑
pao3 Details
('pao3', '奅
('pao3', '泡
('pao3', '炮
pao5 Details
('pao5', '刨
('pao5', '匏
('pao5', '咆
('pao5', '庖
('pao5', '炮
('pao5', '狍
('pao5', '袍
('pao5', '铇
pao6 Details
('pao6', '抱



pi1 Details
('pi1', '帔
('pi1', '披
('pi1', '被
('pi1', '邳
('pi1', '駓
pi2 Details
('pi2', '丕
('pi2', '否
('pi2', '嚭
('pi2', '圮
('pi2', '狉
('pi2', '疕
('pi2', '痞
('pi2', '苤
('pi2', '邳
pi3 Details
('pi3', '媲
('pi3', '嬖
('pi3', '淠
('pi3', '濞
('pi3', '睥
('pi3', '譬
('pi3', '鄙
pi5 Details
('pi5', '疲
('pi5', '罴
('pi5', '脾
('pi5', '蚍
('pi5', '貔
('pi5', '陂
('pi5', '鲏
pi6 Details
('pi6', '屁
pi7 Details
('pi7', '翍



piah4 Details
('piah4', '僻
('piah4', '癖
piah8 Details
('piah8', '僻



pian1 Details
('pian1', '𩩍
pian3 Details
('pian3', '聘
pian5 Details
('pian5', '坪



pig4 Details
('pig4', '匹
('pig4', '噼
('pig4', '苉



pin1 Details
('pin1', '便
pin3 Details
('pin3', '片
pin7 Details
('pin7', '鼻



ping2 Details
('ping2', '牝
('ping2', '砭
('ping2', '窆
('ping2', '贬
ping5 Details
('ping5', '屏
('ping5', '幈
('ping5', '濒
('ping5', '瓶
('ping5', '缾
('ping5', '苹
('ping5', '贫
('ping5', '频
('ping5', '颦



piu3 Details
('piu3', '漂
('piu3', '覆
piu5 Details
('piu5', '罘
('piu5', '芣



piê3 Details
('piê3', '票
piê5 Details
('piê5', '萍
('piê5', '薸
piê6 Details
('piê6', '鳔



piêng1 Details
('piêng1', '偏
('piêng1', '煸
('piêng1', '犏
('piêng1', '篇
('piêng1', '编
('piêng1', '翩
('piêng1', '蝙
('piêng1', '蹁
piêng2 Details
('piêng2', '谝
piêng3 Details
('piêng3', '片
('piêng3', '骗



po1 Details
('po1', '鄱
('po1', '陂
po2 Details
('po2', '叵
('po2', '笸
('po2', '跛
('po2', '钷
('po2', '颇
po5 Details
('po5', '皤
('po5', '繁
po6 Details
('po6', '抱



pog4 Details
('pog4', '仆
('pog4', '幞
('pog4', '扑
('pog4', '朴
('pog4', '濮
('pog4', '爆
('pog4', '璞
('pog4', '襆
('pog4', '蹼
('pog4', '醭
('pog4', '钋
('pog4', '镤
('pog4', '𦢊
pog8 Details
('pog8', '卟



poh4 Details
('poh4', '粕



poin7 Details
('poin7', '办
('poin7', '稗
('poin7', '粺



pong2 Details
('pong2', '捧
('pong2', '搿
pong3 Details
('pong3', '碰
('pong3', '肨
('pong3', '膀
('pong3', '髈
pong5 Details
('pong5', '篷
('pong5', '缝
('pong5', '芃
('pong5', '蓬
('pong5', '鹏



pou1 Details
('pou1', '铺
pou2 Details
('pou2', '剖
('pou2', '匍
('pou2', '圃
('pou2', '掊
('pou2', '普
('pou2', '氆
('pou2', '浦
('pou2', '溥
('pou2', '瓿
('pou2', '甫
('pou2', '簠
('pou2', '脯
('pou2', '裒
('pou2', '谱
('pou2', '踣
('pou2', '镨
('pou2', '黼
pou3 Details
('pou3', '涪
('pou3', '铺
pou5 Details
('pou5', '抔
pou6 Details
('pou6', '簿



pu2 Details
('pu2', '誧
pu5 Details
('pu5', '枹
('pu5', '桴
('pu5', '浮
('pu5', '罦
('pu5', '莆
('pu5', '菩
('pu5', '葡
('pu5', '蒲
('pu5', '蜉
('pu5', '酺
('pu5', '


pua3 Details
('pua3', '破
pua5 Details
('pua5', '婆



puah4 Details
('puah4', '拨
('puah4', '撇
('puah4', '氕
('puah4', '泼
('puah4', '瞥



puan1 Details
('puan1', '潘
('puan1', '番
puan2 Details
('puan2', '颇
puan3 Details
('puan3', '判
puan6 Details
('puan6', '伴



puh4 Details
('puh4', '噗



pui2 Details
('pui2', '呸
('pui2', '啡
pui3 Details
('pui3', '啡
('pui3', '屁



pung1 Details
('pung1', '倴
('pung1', '潘
('pung1', '贲
('pung1', '锛
pung3 Details
('pung3', '喷
('pung3', '坌
pung5 Details
('pung5', '坟
('pung5', '湓
('pung5', '盆
('pung5', '豮
('pung5', '轒
('pung5', '


puê1 Details
('puê1', '坏
('puê1', '坯
('puê1', '肧
('puê1', '胚
('puê1', '醅
puê3 Details
('puê3', '杮
('puê3', '配
puê5 Details
('puê5', '皮
('puê5', '裴
('puê5', '裵
('puê5', '铍
puê6 Details
('puê6', '被



puêh8 Details
('puêh8', '诐



puêng1 Details
('puêng1', '幡
('puêng1', '燔
('puêng1', '璠
('puêng1', '膰
('puêng1', '蕃
('puêng1', '藩
('puêng1', '蹯
puêng3 Details
('puêng3', '判
('puêng3', '拌
('puêng3', '泮
('puêng3', '畔
('puêng3', '绊
('puêng3', '胖
puêng5 Details
('puêng5', '幋
('puêng5', '槃
('puêng5', '盘
('puêng5', '磐
('puêng5', '磻
('puêng5', '般
('puêng5', '蟠
('puêng5', '蹒



pê3 Details
('pê3', '帕



pêg4 Details
('pêg4', '劈
('pêg4', '匐
('pêg4', '哔
('pêg4', '擗
('pêg4', '擘
('pêg4', '珀
('pêg4', '甓
('pêg4', '碧
('pêg4', '襞
('pêg4', '躄
('pêg4', '辟
('pêg4', '鐾
('pêg4', '霹
('pêg4', '魄
('pêg4', '鸊



pên5 Details
('pên5', '平
('pên5', '彭
('pên5', '澎
('pên5', '膨
('pên5', '蟛



pêng1 Details
('pêng1', '俜
('pêng1', '姘
('pêng1', '拚
('pêng1', '拼
('pêng1', '烹
pêng3 Details
('pêng3', '娉
('pêng3', '聘
('pêng3', '骋
pêng5 Details
('pêng5', '凭
('pêng5', '凴
('pêng5', '坪
('pêng5', '堋
('pêng5', '帡
('pêng5', '平
('pêng5', '怦
('pêng5', '憑
('pêng5', '抨
('pêng5', '朋
('pêng5', '枰
('pêng5', '砰
('pêng5', '硼
('pêng5', '萍
('pêng5', '评
('pêng5', '鬅
('pêng5', '鲆



re2 Details
('re2', '尔
('re2', '汝
('re2', '洱
('re2', '玺
('re2', '耳
('re2', '鈢
('re2', '铒
re5 Details
('re5', '侕
('re5', '而
('re5', '荋
('re5', '鸸
re6 Details
('re6', '女
('re6', '字
('re6', '腻
('re6', '贰
('re6', '饵



ri5 Details
('ri5', '儿
ri6 Details
('ri6', '二
('ri6', '弍
ri7 Details
('ri7', '二
('ri7', '佴
('ri7', '刵
('ri7', '字
('ri7', '寺
('ri7', '牸
('ri7', '珥
('ri7', '饵



ria2 Details
('ria2', '偌
('ria2', '喏
('ria2', '惹


riag8 Details
('riag8', '叒
('riag8', '婼
('riag8', '弱
('riag8', '箬
('riag8', '若
('riag8', '蒻
('riag8', '


riang2 Details
('riang2', '嚷
('riang2', '壤
('riang2', '攘
('riang2', '禳
('riang2', '穰
('riang2', '酿
riang5 Details
('riang5', '瓤
('riang5', '蘘
riang6 Details
('riang6', '让



rib8 Details
('rib8', '入


rig8 Details
('rig8', '日



rih8 Details
('rih8', '廿



rim2 Details
('rim2', '仞
('rim2', '刃
('rim2', '刄
('rim2', '忍
('rim2', '恁
('rim2', '牣
('rim2', '稔
('rim2', '纫
('rim2', '荏
('rim2', '赁
('rim2', '轫
('rim2', '韧
('rim2', '饪
rim6 Details
('rim6', '任
('rim6', '壬
('rim6', '妊
('rim6', '姙
('rim6', '纴
('rim6', '衽
('rim6', '袵
('rim6', '赁
rim7 Details
('rim7', '任



ring5 Details
('ring5', '人
('ring5', '仁
('ring5', '忈
ring7 Details
('ring7', '认



riu5 Details
('riu5', '揉
('riu5', '柔
('riu5', '煣
('riu5', '糅
('riu5', '蹂
('riu5', '鞣



riê5 Details
('riê5', '桡
riê7 Details
('riê7', '尿
('riê7', '脲



riêg8 Details
('riêg8', '热
('riêg8', '爇



riêng5 Details
('riêng5', '然
('riêng5', '燃



rog8 Details
('rog8', '溽
('rog8', '缛
('rog8', '蓐
('rog8', '褥
('rog8', '辱



rong2 Details
('rong2', '冗
rong5 Details
('rong5', '仍
('rong5', '戎
('rong5', '狨
('rong5', '绒
('rong5', '茸



ru2 Details
('ru2', '乳
('ru2', '愈
('ru2', '擩
('ru2', '瘉
('ru2', '貐
ru5 Details
('ru5', '俞
('ru5', '儒
('ru5', '嚅
('ru5', '如
('ru5', '孺
('ru5', '嵛
('ru5', '庾
('ru5', '愉
('ru5', '挐
('ru5', '揄
('ru5', '榆
('ru5', '毹
('ru5', '洳
('ru5', '渝
('ru5', '濡
('ru5', '濶
('ru5', '瑜
('ru5', '瘐
('ru5', '窬
('ru5', '腴
('ru5', '臾
('ru5', '茹
('ru5', '萸
('ru5', '薷
('ru5', '蝓
('ru5', '蠕
('ru5', '襦
('ru5', '觎
('ru5', '谀
('ru5', '逾
('ru5', '铷
('ru5', '颥
ru6 Details
('ru6', '吁
('ru6', '喻
('ru6', '裕
('ru6', '谕



ruah8 Details
('ruah8', '热



rui5 Details
('rui5', '唯
('rui5', '帷
('rui5', '惟
('rui5', '潍
('rui5', '维
rui6 Details
('rui6', '遗



rung2 Details
('rung2', '允
('rung2', '吮
('rung2', '狁
rung6 Details
('rung6', '润
rung7 Details
('rung7', '闰
('rung7', '韧



ruê5 Details
('ruê5', '挼
('ruê5', '捼
ruê6 Details
('ruê6', '叡
('ruê6', '枘
('ruê6', '睿
('ruê6', '蚋
('ruê6', '锐
ruê7 Details
('ruê7', '汭
('ruê7', '芮



ruêg8 Details
('ruêg8', '悦
('ruêg8', '说



ruêng2 Details
('ruêng2', '纂
('ruêng2', '转


rêng5 Details
('rêng5', '扔
('rêng5', '礽
rêng6 Details
('rêng6', '媵



sa1 Details
('sa1', '抄
('sa1', '沙
('sa1', '砂
('sa1', '筲
('sa1', '莎
('sa1', '蕱
sa3 Details
('sa3', '哨
sa6 Details
('sa6', '傻
('sa6', '儍
('sa6', '啥



sab4 Details
('sab4', '卅
('sab4', '嗄
('sab4', '靸
('sab4', '飒
sab8 Details
('sab8', '刹



sag4 Details
('sag4', '僿
('sag4', '刹
('sag4', '噻
('sag4', '塞
('sag4', '撒
('sag4', '萨
('sag4', '虱



sai1 Details
('sai1', '师
('sai1', '思
('sai1', '揌
('sai1', '樨
('sai1', '犀
('sai1', '狮
('sai1', '私
('sai1', '筛
('sai1', '腮
('sai1', '蛳
('sai1', '西
('sai1', '酾
('sai1', '顋
('sai1', '鳃
sai2 Details
('sai2', '使
('sai2', '屎
('sai2', '驶
sai3 Details
('sai3', '使
('sai3', '塞
('sai3', '壻
('sai3', '婿
('sai3', '晒
('sai3', '洒
('sai3', '赛
sai5 Details
('sai5', '豺
sai6 Details
('sai6', '柹
('sai6', '柿
sai7 Details
('sai7', '倳
('sai7', '姒



sam1 Details
('sam1', '三
('sam1', '杉
('sam1', '毵
('sam1', '糁
('sam1', '钐
sam2 Details
('sam2', '糁
sam3 Details
('sam3', '钐



san1 Details
('san1', '三
('san1', '仨
('san1', '叁
('san1', '叄
('san1', '弎
('san1', '衫



sang1 Details
('sang1', '三
('sang1', '删
('sang1', '双
('sang1', '姗
('sang1', '山
('sang1', '松
('sang1', '栅
('sang1', '泷
('sang1', '潸
('sang1', '澘
('sang1', '珊
('sang1', '羴
('sang1', '舢
('sang1', '芟
('sang1', '讪
('sang1', '跚
('sang1', '鉎
sang2 Details
('sang2', '㾪
('sang2', '嗓
('sang2', '瘦
sang3 Details
('sang3', '丧
('sang3', '擤
('sang3', '疝
('sang3', '送
('sang3', '霰



sao1 Details
('sao1', '捎
('sao1', '搔
('sao1', '梢
('sao1', '艄
('sao1', '蛸
('sao1', '骚
sao2 Details
('sao2', '嫂
sao3 Details
('sao3', '哨
('sao3', '啸
('sao3', '嗽
('sao3', '嘨
('sao3', '埽
('sao3', '扫
('sao3', '梢
('sao3', '潲



se1 Details
('se1', '凘
('se1', '厮
('se1', '厶
('se1', '司
('se1', '嘶
('se1', '师
('se1', '思
('se1', '撕
('se1', '斯
('se1', '楒
('se1', '浉
('se1', '澌
('se1', '私
('se1', '缌
('se1', '罳
('se1', '虒
('se1', '锶
se2 Details
('se2', '史
se3 Details
('se3', '四
('se3', '思
('se3', '泗
('se3', '笥
('se3', '肆
('se3', '赐
('se3', '驷
se5 Details
('se5', '祠
('se5', '茌
('se5', '词
('se5', '辞
se6 Details
('se6', '事
('se6', '仕
('se6', '伺
('se6', '似
('se6', '佀
('se6', '俟
('se6', '嗣
('se6', '士
('se6', '姒
('se6', '屿
('se6', '峙
('se6', '汜
('se6', '涘
('se6', '祀
('se6', '耜
('se6', '食
se7 Details
('se7', '事



seng1 Details
('seng1', '丧
('seng1', '嗤
('seng1', '孀
('seng1', '孙
('seng1', '桑
('seng1', '酸
('seng1', '霜
('seng1', '鹴
seng2 Details
('seng2', '耍
seng3 Details
('seng3', '筭
('seng3', '算
('seng3', '蒜


si1 Details
('si1', '䴓
('si1', '丝
('si1', '厕
('si1', '司
('si1', '咝
('si1', '尸
('si1', '思
('si1', '施
('si1', '栖
('si1', '樨
('si1', '氥
('si1', '硒
('si1', '私
('si1', '絁
('si1', '茜
('si1', '葹
('si1', '蒨
('si1', '蓍
('si1', '西
('si1', '诗
('si1', '鸶
si2 Details
('si2', '兕
('si2', '始
('si2', '屣
('si2', '弛
('si2', '枲
('si2', '死
('si2', '矢
('si2', '葸
('si2', '蓰
('si2', '豕
si3 Details
('si3', '世
('si3', '丗
('si3', '势
('si3', '四
('si3', '肆
si5 Details
('si5', '匙
('si5', '埘
('si5', '时
('si5', '莳
('si5', '辞
('si5', '鲥
si6 Details
('si6', '侍
('si6', '峙
('si6', '恃
('si6', '是
('si6', '昰
('si6', '氏
('si6', '视
si7 Details
('si7', '嗜
('si7', '噬
('si7', '晢
('si7', '示
('si7', '筮
('si7', '视
('si7', '誓
('si7', '豉
('si7', '逝



sia1 Details
('sia1', '斜
sia2 Details
('sia2', '写
('sia2', '冩
sia3 Details
('sia3', '卸
('sia3', '厍
('sia3', '泻
('sia3', '猞
('sia3', '舍
('sia3', '贳
('sia3', '赦
sia5 Details
('sia5', '佘
('sia5', '斜
('sia5', '畬
('sia5', '畲
('sia5', '邪
sia6 Details
('sia6', '灺
('sia6', '社
sia7 Details
('sia7', '射
('sia7', '榭
('sia7', '谢
('sia7', '麝



siah4 Details
('siah4', '削
('siah4', '箾
('siah4', '锡
siah8 Details
('siah8', '席



sian1 Details
('sian1', '声
sian3 Details
('sian3', '圣
sian5 Details
('sian5', '城
('sian5', '成
sian7 Details
('sian7', '盛
('sian7', '𣛮



siang1 Details
('siang1', '商
('siang1', '墒
('siang1', '殇
('siang1', '氙
('siang1', '汤
('siang1', '湘
('siang1', '熵
('siang1', '瓖
('siang1', '相
('siang1', '缃
('siang1', '襄
('siang1', '觞
('siang1', '酰
('siang1', '镶
('siang1', '骧
siang2 Details
('siang2', '想
('siang2', '鲞
siang3 Details
('siang3', '信
('siang3', '扇
('siang3', '相
siang5 Details
('siang5', '上
('siang5', '嫦
('siang5', '尝
('siang5', '庠
('siang5', '徜
('siang5', '祥
('siang5', '翔
('siang5', '裳
('siang5', '详
siang6 Details
('siang6', '上
('siang6', '像
('siang6', '尚
('siang6', '绱
('siang6', '象



sib4 Details
('sib4', '湿
('sib4', '隰
sib8 Details
('sib8', '习
('sib8', '什
('sib8', '嶍
('sib8', '拾
('sib8', '熠
('sib8', '袭
('sib8', '鳛



sig4 Details
('sig4', '失
('sig4', '室
sig8 Details
('sig8', '实
('sig8', '寔
('sig8', '植
('sig8', '殖
('sig8', '湜
('sig8', '稙
('sig8', '翼
('sig8', '食
('sig8', '

sih4 Details
('sih4', '薛
sih8 Details
('sih8', '蚀
('sih8', '食



sim1 Details
('sim1', '心
('sim1', '新
('sim1', '芯
sim2 Details
('sim2', '婶
('sim2', '审
('sim2', '慎
('sim2', '沁
('sim2', '沈
('sim2', '瘆
('sim2', '稔
('sim2', '谂
('sim2', '谉
sim3 Details
('sim3', '瘆
sim5 Details
('sim5', '忱
('sim5', '谌
sim6 Details
('sim6', '什
('sim6', '椹
('sim6', '甚
('sim6', '葚



sin3 Details
('sin3', '扇
('sin3', '搧



sing1 Details
('sing1', '伸
('sing1', '先
('sing1', '呻
('sing1', '新
('sing1', '燊
('sing1', '珅
('sing1', '申
('sing1', '砷
('sing1', '绅
('sing1', '胂
('sing1', '莘
('sing1', '薪
('sing1', '身
('sing1', '辛
('sing1', '锌
('sing1', '骍
sing3 Details
('sing3', '信
('sing3', '囟
('sing3', '汛
('sing3', '芯
('sing3', '讯
('sing3', '迅
sing5 Details
('sing5', '娠
('sing5', '宸
('sing5', '承
('sing5', '晨
('sing5', '渑
('sing5', '神
('sing5', '绳
('sing5', '蜃
('sing5', '蝇
('sing5', '辰
sing7 Details
('sing7', '剩



siu1 Details
('siu1', '修
('siu1', '収
('siu1', '收
('siu1', '梳
('siu1', '羞
('siu1', '馐
siu2 Details
('siu2', '守
('siu2', '帚
('siu2', '首
('siu2', '黍
siu3 Details
('siu3', '兽
('siu3', '宿
('siu3', '岫
('siu3', '狩
('siu3', '琇
('siu3', '秀
('siu3', '绣
('siu3', '袖
('siu3', '锈
siu5 Details
('siu5', '泅
siu6 Details
('siu6', '受
('siu6', '授
('siu6', '绶
siu7 Details
('siu7', '寿



siê1 Details
('siê1', '烧
('siê1', '相
('siê1', '霄
siê2 Details
('siê2', '小
siê7 Details
('siê7', '邵



siêg4 Details
('siêg4', '亵
('siêg4', '卨
('siêg4', '契
('siêg4', '屑
('siêg4', '楔
('siêg4', '渫
('siêg4', '设



siêh4 Details
('siêh4', '惜
siêh8 Details
('siêh8', '液
('siêh8', '石



siên1 Details
('siên1', '伤
('siên1', '厢
('siên1', '箱
('siên1', '镶
siên2 Details
('siên2', '赏
siên3 Details
('siên3', '像
('siên3', '相
('siên3', '肖
siên5 Details
('siên5', '偿
('siên5', '尝
('siên5', '常
siên6 Details
('siên6', '想
siên7 Details
('siên7', '尚



siêng1 Details
('siêng1', '仙
('siêng1', '僊
('siêng1', '籼
siêng2 Details
('siêng2', '冼
('siêng2', '哂
('siêng2', '洗
('siêng2', '燹
('siêng2', '狝
('siêng2', '癣
('siêng2', '矧
('siêng2', '藓
('siêng2', '跣
('siêng2', '铣
('siêng2', '鲜
siêng3 Details
('siêng3', '傓
('siêng3', '煽
('siêng3', '骟
siêng5 Details
('siêng5', '单
('siêng5', '嬗
('siêng5', '澶
('siêng5', '阐
siêng6 Details
('siêng6', '单
('siêng6', '善
('siêng6', '墡
('siêng6', '擅
('siêng6', '缮
('siêng6', '肾
('siêng6', '膳
('siêng6', '蟮
('siêng6', '鄯
('siêng6', '鐥
('siêng6', '饍
('siêng6', '鳝



so1 Details
('so1', '唆
('so1', '嗦
('so1', '娑
('so1', '挱
('so1', '挲
('so1', '搓
('so1', '梭
('so1', '疎
('so1', '疏
('so1', '睃
('so1', '羧
('so1', '莎
('so1', '蔬
so2 Details
('so2', '唢
('so2', '嫂
('so2', '所
('so2', '琐
('so2', '锁
so3 Details
('so3', '疎
('so3', '疏



sog4 Details
('sog4', '俶
('sog4', '叔
('sog4', '塑
('sog4', '夙
('sog4', '寂
('sog4', '数
('sog4', '束
('sog4', '涑
('sog4', '淑
('sog4', '漱
('sog4', '潄
('sog4', '簌
('sog4', '索
('sog4', '缩
('sog4', '肃
('sog4', '菽
('sog4', '蓿
('sog4', '蔌
('sog4', '觫
('sog4', '谡
('sog4', '速
('sog4', '鹔
sog8 Details
('sog8', '俗
('sog8', '塾
('sog8', '孰
('sog8', '属
('sog8', '续
('sog8', '赎



soh4 Details
('soh4', '索
('soh4', '踅
('soh4', '雪
('soh4', '鳕



soi2 Details
('soi2', '洒
('soi2', '洗
soi3 Details
('soi3', '细



soin1 Details
('soin1', '先
('soin1', '嘶



song1 Details
('song1', '忪
('song1', '松
song2 Details
('song2', '怂
('song2', '悚
('song2', '竦
('song2', '耸
song3 Details
('song3', '宋
song5 Details
('song5', '凇
('song5', '崧
('song5', '嵩
('song5', '松
('song5', '淞
('song5', '菘
song6 Details
('song6', '讼
('song6', '诵
('song6', '颂



sou1 Details
('sou1', '稣
('sou1', '苏
('sou1', '酥
('sou1', '锼
sou2 Details
('sou2', '叟
('sou2', '嗖
('sou2', '嗾
('sou2', '廋
('sou2', '擞
('sou2', '溲
('sou2', '瘦
('sou2', '瞍
('sou2', '艘
('sou2', '薮



su1 Details
('su1', '姝
('su1', '媭
('su1', '尿
('su1', '抒
('su1', '摅
('su1', '毹
('su1', '湑
('su1', '糈
('su1', '纾
('su1', '胥
('su1', '舒
('su1', '谞
('su1', '输
('su1', '需
('su1', '须
su2 Details
('su2', '墅
('su2', '暑
('su2', '曙
('su2', '杵
('su2', '杼
('su2', '渚
('su2', '绪
('su2', '署
('su2', '褚
('su2', '黍
su3 Details
('su3', '嗉
('su3', '塑
('su3', '庶
('su3', '庻
('su3', '恕
('su3', '愫
('su3', '数
('su3', '素
('su3', '絮
('su3', '腧
('su3', '诉
su5 Details
('su5', '殊
('su5', '殳
('su5', '蜍
su6 Details
('su6', '叙
('su6', '序
('su6', '树
('su6', '溆
('su6', '澍
('su6', '竖



sua1 Details
('sua1', '沙
('sua1', '痧
('sua1', '砂
('sua1', '鲨
sua2 Details
('sua2', '徙



suag4 Details
('suag4', '塑
('suag4', '搠
('suag4', '数
('suag4', '朔
('suag4', '槊
('suag4', '泝
('suag4', '溯
('suag4', '蒴



suah4 Details
('suah4', '宿
('suah4', '撒
('suah4', '杀
('suah4', '煞
('suah4', '铩



suai1 Details
('suai1', '甩



suain7 Details
('suain7', '榱
('suain7', '檨



suan1 Details
('suan1', '山
('suan1', '汕
suan2 Details
('suan2', '产
('suan2', '散
('suan2', '浐
('suan2', '產
suan3 Details
('suan3', '伞
('suan3', '散
('suan3', '汕
('suan3', '线
('suan3', '缐
('suan3', '腺
('suan3', '霰
('suan3', '馓
suan5 Details
('suan5', '腺



suang1 Details
('suang1', '喧
('suang1', '宣
('suang1', '煊
('suang1', '闩
suang2 Details
('suang2', '搡
('suang2', '爽
('suang2', '磉
('suang2', '颡



sug4 Details
('sug4', '卹
('sug4', '屑
('sug4', '恤
('sug4', '戌
('sug4', '摔
('sug4', '率
('sug4', '窣
('sug4', '蟀
sug8 Details
('sug8', '术
('sug8', '沭
('sug8', '述
('sug8', '鉥



suh4 Details
('suh4', '嗍



sui1 Details
('sui1', '哀
('sui1', '尿
('sui1', '榱
('sui1', '簑
('sui1', '绥
('sui1', '缞
('sui1', '荽
('sui1', '蓑
('sui1', '虽
sui2 Details
('sui2', '嶲
sui5 Details
('sui5', '垂
('sui5', '燧
('sui5', '绥
('sui5', '蕤
('sui5', '谁
('sui5', '遂
('sui5', '邃
('sui5', '陲
('sui5', '隋
('sui5', '随
sui6 Details
('sui6', '瑞
('sui6', '睡
sui7 Details
('sui7', '穗
('sui7', '隧



sung1 Details
('sung1', '孙
('sung1', '狲
('sung1', '绚
('sung1', '荪
('sung1', '飧
('sung1', '飱
sung2 Details
('sung2', '损
('sung2', '楯
('sung2', '榫
('sung2', '笋
('sung2', '衮
sung3 Details
('sung3', '噀
('sung3', '孙
('sung3', '巽
('sung3', '瞬
('sung3', '舜
('sung3', '逊
sung5 Details
('sung5', '峋
('sung5', '巡
('sung5', '廵
('sung5', '徇
('sung5', '循
('sung5', '恂
('sung5', '旬
('sung5', '栒
('sung5', '殉
('sung5', '洵
('sung5', '珣
('sung5', '纯
('sung5', '荀
('sung5', '莼
('sung5', '询
('sung5', '郇
('sung5', '醇
('sung5', '醕
('sung5', '錞
('sung5', '驯
('sung5', '鹑
sung6 Details
('sung6', '顺



suê1 Details
('suê1', '哀
('suê1', '衰
suê3 Details
('suê3', '岁
('suê3', '帅
('suê3', '帨
('suê3', '戍
('suê3', '税
('suê3', '蜕
('suê3', '说
('suê3', '


suêh4 Details
('suêh4', '刷
('suêh4', '唰
('suêh4', '涮
('suêh4', '说



suêng1 Details
('suêng1', '喧
('suêng1', '宣
('suêng1', '揎
('suêng1', '暄
('suêng1', '朘
('suêng1', '楥
('suêng1', '楦
('suêng1', '渲
('suêng1', '煊
('suêng1', '狻
('suêng1', '瑄
('suêng1', '萱
('suêng1', '萲
('suêng1', '谖
suêng2 Details
('suêng2', '选
suêng3 Details
('suêng3', '氽
('suêng3', '汆
('suêng3', '涮
suêng5 Details
('suêng5', '旋
('suêng5', '漩
('suêng5', '璇
('suêng5', '璿
('suêng5', '镟
suêng6 Details
('suêng6', '噀
('suêng6', '漩
suêng7 Details
('suêng7', '旋



sê1 Details
('sê1', '些
('sê1', '纱
('sê1', '裟
sê5 Details
('sê5', '侪



sêg4 Details
('sêg4', '啬
('sêg4', '埴
('sêg4', '夕
('sêg4', '奭
('sêg4', '媳
('sêg4', '式
('sêg4', '息
('sêg4', '悉
('sêg4', '拭
('sêg4', '掷
('sêg4', '摵
('sêg4', '昔
('sêg4', '晰
('sêg4', '晳
('sêg4', '析
('sêg4', '植
('sêg4', '殖
('sêg4', '汐
('sêg4', '淅
('sêg4', '潟
('sêg4', '熄
('sêg4', '瑟
('sêg4', '皙
('sêg4', '矽
('sêg4', '硕
('sêg4', '穑
('sêg4', '穸
('sêg4', '窸
('sêg4', '舄
('sêg4', '色
('sêg4', '蜥
('sêg4', '螅
('sêg4', '螫
('sêg4', '蟋
('sêg4', '识
('sêg4', '轼
('sêg4', '适
('sêg4', '释
('sêg4', '铯
('sêg4', '饰
sêg8 Details
('sêg8', '熟
('sêg8', '鼫



sên1 Details
('sên1', '牲
('sên1', '生
('sên1', '鉎
sên2 Details
('sên2', '省
sên3 Details
('sên3', '姓
('sên3', '性



sêng1 Details
('sêng1', '升
('sêng1', '声
('sêng1', '惺
('sêng1', '旌
('sêng1', '牲
('sêng1', '猩
('sêng1', '生
('sêng1', '甥
('sêng1', '笙
('sêng1', '胜
('sêng1', '腥
sêng2 Details
('sêng2', '省
('sêng2', '眚
sêng3 Details
('sêng3', '圣
('sêng3', '胜
sêng5 Details
('sêng5', '丞
('sêng5', '乗
('sêng5', '乘
('sêng5', '宬
('sêng5', '成
('sêng5', '承
('sêng5', '松
('sêng5', '榕
('sêng5', '诚
('sêng5', '铖
sêng6 Details
('sêng6', '乗
('sêng6', '乘
('sêng6', '嵊
('sêng6', '晟
('sêng6', '盛


ta1 Details
('ta1', '他
('ta1', '她
('ta1', '它
('ta1', '怹
('ta1', '牠
('ta1', '铊
('ta1', '


tab4 Details
('tab4', '塌
('tab4', '榻
('tab4', '溻
('tab4', '滭
('tab4', '褟
('tab4', '蹋
('tab4', '錔
('tab4', '鳎
tab8 Details
('tab8', '塌



tag4 Details
('tag4', '塞
('tag4', '拓
('tag4', '挞
('tag4', '橐
('tag4', '漯
('tag4', '踢
('tag4', '闼
tag8 Details
('tag8', '读


tah4 Details
('tah4', '塔
('tah4', '墖
('tah4', '趿
tah8 Details
('tah8', '叠
('tah8', '曡
('tah8', '氎
('tah8', '沓



tai1 Details
('tai1', '筛
('tai1', '苔
tai2 Details
('tai2', '呔
tai3 Details
('tai3', '傣
('tai3', '大
('tai3', '太
('tai3', '态
('tai3', '汰
('tai3', '泰
('tai3', '肽
('tai3', '虿
('tai3', '酞
('tai3', '钛
tai5 Details
('tai5', '刣
('tai5', '台
('tai5', '抬
('tai5', '擡
('tai5', '治
('tai5', '炱
('tai5', '薹
('tai5', '邰
('tai5', '骀
('tai5', '鲐
tai6 Details
('tai6', '待



tam1 Details
('tam1', '贪
tam2 Details
('tam2', '菼
tam3 Details
('tam3', '叹
('tam3', '探
tam5 Details
('tam5', '坛
('tam5', '掸
('tam5', '昙
('tam5', '潭
('tam5', '澹
('tam5', '痰
('tam5', '覃
('tam5', '谈
('tam5', '谭
('tam5', '郯


tang1 Details
('tang1', '坍
('tang1', '熥
('tang1', '瘫
('tang1', '蛏
('tang1', '蹚
('tang1', '通
('tang1', '镗
tang2 Details
('tang2', '倘
('tang2', '偿
('tang2', '傥
('tang2', '坦
('tang2', '帑
('tang2', '忐
('tang2', '桶
('tang2', '毯
('tang2', '淌
('tang2', '疸
('tang2', '耥
('tang2', '袒
('tang2', '襢
('tang2', '趟
('tang2', '躺
('tang2', '钽
('tang2', '镋
tang3 Details
('tang3', '亘
('tang3', '赚
('tang3', '趁
tang5 Details
('tang5', '唐
('tang5', '堂
('tang5', '塘
('tang5', '弹
('tang5', '搪
('tang5', '桐
('tang5', '棠
('tang5', '榃
('tang5', '樘
('tang5', '檀
('tang5', '溏
('tang5', '瑭
('tang5', '瞠
('tang5', '膛
('tang5', '虫
('tang5', '螗
('tang5', '螳
('tang5', '赯
('tang5', '鄌
('tang5', '镗
tang6 Details
('tang6', '动



tao1 Details
('tao1', '偷
('tao1', '叨
('tao1', '婾
('tao1', '洮
('tao1', '滔
('tao1', '绦
('tao1', '韬
('tao1', '饕
tao2 Details
('tao2', '㪗
('tao2', '敍
('tao2', '敨
tao3 Details
('tao3', '套
('tao3', '透
('tao3', '黈
tao5 Details
('tao5', '匋
('tao5', '咷
('tao5', '头
('tao5', '帱
('tao5', '掏
('tao5', '淘
('tao5', '醄
('tao5', '陶



teng1 Details
('teng1', '汤
teng3 Details
('teng3', '烫
('teng3', '煺
('teng3', '褪
teng5 Details
('teng5', '糖
('teng5', '鎕
teng7 Details
('teng7', '捅



ti1 Details
('ti1', '螭
('ti1', '鷉
('ti1', '黐
ti2 Details
('ti2', '体
('ti2', '躰
('ti2', '軆
('ti2', '體
ti3 Details
('ti3', '剃
('ti3', '啻
('ti3', '嚏
('ti3', '屉
('ti3', '替
('ti3', '涕
('ti3', '滞
('ti3', '睇
('ti3', '禘
('ti3', '缔
('ti3', '翄
('ti3', '翅
('ti3', '薙
('ti3', '谛
('ti3', '髢
('ti3', '髰
ti5 Details
('ti5', '啼
('ti5', '嗁
('ti5', '持
('ti5', '提
('ti5', '禔
('ti5', '绨
('ti5', '缇
('ti5', '荑
('ti5', '菭
('ti5', '醍
('ti5', '騠
('ti5', '鹈
ti6 Details
('ti6', '痔



tiah4 Details
('tiah4', '拆



tian1 Details
('tian1', '厅
('tian1', '听
tian3 Details
('tian3', '痛
tian5 Details
('tian5', '呈
('tian5', '程



tiang3 Details
('tiang3', '畅
('tiang3', '鬯



tih4 Details
('tih4', '忒
('tih4', '铁



tin1 Details
('tin1', '天
('tin1', '添



ting5 Details
('ting5', '陈



tiog4 Details
('tiog4', '畜
('tiog4', '蓄



tiu1 Details
('tiu1', '䌷
('tiu1', '抽
('tiu1', '瘳
tiu2 Details
('tiu2', '丑
tiu3 Details
('tiu3', '斢
tiu5 Details
('tiu5', '俦
('tiu5', '帱
('tiu5', '惆
('tiu5', '涛
('tiu5', '畴
('tiu5', '筹
('tiu5', '踌



tiê1 Details
('tiê1', '挑
tiê3 Details
('tiê3', '粜



tiêg4 Details
('tiêg4', '彻
('tiêg4', '撤
('tiêg4', '澈
('tiêg4', '辙
('tiêg4', '餮



tiêng1 Details
('tiêng1', '兲
('tiêng1', '天
tiêng2 Details
('tiêng2', '腆
('tiêng2', '蒇
tiêng5 Details
('tiêng5', '填
('tiêng5', '廛
('tiêng5', '瀍
('tiêng5', '瞋
('tiêng5', '钿
('tiêng5', '阗



to1 Details
('to1', '推
('to1', '胎
to2 Details
('to2', '妥
('to2', '椭
('to2', '讨
to3 Details
('to3', '蜕
('to3', '褪
('to3', '退
to5 Details
('to5', '佗
('to5', '坨
('to5', '柁
('to5', '桃
('to5', '沱
('to5', '沲
('to5', '洮
('to5', '砣
('to5', '砤
('to5', '萄
('to5', '跎
('to5', '酡
('to5', '陀
('to5', '驮
('to5', '鸵
('to5', '鼍
('to5', '鼧
to6 Details
('to6', '唾



tog4 Details
('tog4', '亍
('tog4', '秃
('tog4', '跅



toh4 Details
('toh4', '庹
('toh4', '托
('toh4', '柝
('toh4', '箨
('toh4', '萚
('toh4', '饦
('toh4', '魄
toh8 Details
('toh8', '驼



toi1 Details
('toi1', '钗
toi2 Details
('toi2', '体
toi3 Details
('toi3', '代
('toi3', '替



toin2 Details
('toin2', '看
('toin2', '睇
('toin2', '躰
('toin2', '軆
('toin2', '體


tong1 Details
('tong1', '痌
('tong1', '通
tong2 Details
('tong2', '冢
('tong2', '宠
('tong2', '捅
('tong2', '统
tong3 Details
('tong3', '恸
('tong3', '痛
tong5 Details
('tong5', '仝
('tong5', '佟
('tong5', '侗
('tong5', '僮
('tong5', '同
('tong5', '垌
('tong5', '峂
('tong5', '峒
('tong5', '幢
('tong5', '彤
('tong5', '恫
('tong5', '憧
('tong5', '曈
('tong5', '桐
('tong5', '洞
('tong5', '潼
('tong5', '烔
('tong5', '疃
('tong5', '瞳
('tong5', '砼
('tong5', '童
('tong5', '茼
('tong5', '酮
('tong5', '鲖
tong7 Details
('tong7', '洞
('tong7', '胴



tou2 Details
('tou2', '土
('tou2', '钍
tou3 Details
('tou3', '兎
('tou3', '兔
('tou3', '吐
('tou3', '堍
tou5 Details
('tou5', '塗
('tou5', '涂



tu5 Details
('tu5', '储
('tu5', '图
('tu5', '塗
('tu5', '徒
('tu5', '涂
('tu5', '滁
('tu5', '荼
('tu5', '躇
('tu5', '途
('tu5', '酴



tua1 Details
('tua1', '拖
tua7 Details
('tua7', '汏



tuah4 Details
('tuah4', '汏
('tuah4', '獭



tuan1 Details
('tuan1', '摊
('tuan1', '滩
('tuan1', '瘫
tuan3 Details
('tuan3', '炭
('tuan3', '碳
('tuan3', '羰



tug4 Details
('tug4', '怵
('tug4', '脱
('tug4', '饳
('tug4', '黜



tuh8 Details
('tuh8', '腯



tui1 Details
('tui1', '推
('tui1', '梯
tui2 Details
('tui2', '腿
tui5 Details
('tui5', '槌
('tui5', '锤
tui7 Details
('tui7', '缒



tung1 Details
('tung1', '吞
('tung1', '饨
tung2 Details
('tung2', '氽
tung5 Details
('tung5', '囤
('tung5', '尘
('tung5', '屯
('tung5', '臀
('tung5', '臋
('tung5', '豚
('tung5', '鲀



tuê1 Details
('tuê1', '颓



tuêng5 Details
('tuêng5', '传
('tuêng5', '团
('tuêng5', '抟



tê1 Details
('tê1', '挓



têg4 Details
('têg4', '倜
('têg4', '剔
('têg4', '勅
('têg4', '彳
('têg4', '忑
('têg4', '忒
('têg4', '惕
('têg4', '慝
('têg4', '搐
('têg4', '敕
('têg4', '磔
('têg4', '秃
('têg4', '裼
('têg4', '踢
('têg4', '铽
('têg4', '陟
('têg4', '饬
('têg4', '骘



têh4 Details
('têh4', '姹
têh8 Details
('têh8', '宅



tên1 Details
('tên1', '撑
('tên1', '橕
tên3 Details
('tên3', '挰



têng1 Details
('têng1', '桯
('têng1', '汀
('têng1', '烃
('têng1', '窓
('têng1', '窗
('têng1', '赪
têng2 Details
('têng2', '侹
('têng2', '惩
('têng2', '挺
('têng2', '梃
('têng2', '珽
('têng2', '町
('têng2', '艇
('têng2', '逞
('têng2', '郢
('têng2', '铤
('têng2', '颋
('têng2', '颍
('têng2', '颕
('têng2', '颖
têng3 Details
('têng3', '听
têng5 Details
('têng5', '停
('têng5', '堘
('têng5', '塍
('têng5', '婷
('têng5', '庭
('têng5', '廷
('têng5', '渟
('têng5', '滕
('têng5', '澂
('têng5', '澄
('têng5', '瞠
('têng5', '瞪
('têng5', '程
('têng5', '縢
('têng5', '腾
('têng5', '莛
('têng5', '蜓
('têng5', '螣
('têng5', '誊
('têng5', '酲
('têng5', '霆
têng6 Details
('têng6', '等



u1 Details
('u1', '乌
('u1', '于
('u1', '吁
('u1', '呜
('u1', '呼
('u1', '嘑
('u1', '圩
('u1', '圬
('u1', '恶
('u1', '捂
('u1', '摀
('u1', '杇
('u1', '污
('u1', '洿
('u1', '盂
('u1', '盱
('u1', '竽
('u1', '纡
('u1', '訏
('u1', '迂
('u1', '邘
('u1', '邬
('u1', '雩
u2 Details
('u2', '五
('u2', '伛
('u2', '妪
('u2', '宇
('u2', '敔
('u2', '禹
('u2', '羽
('u2', '雨
u3 Details
('u3', '坞
('u3', '垭
('u3', '恶
('u3', '涴
('u3', '焐
u5 Details
('u5', '五
('u5', '吾
('u5', '圄
('u5', '娱
('u5', '浯
('u5', '痦
('u5', '郚
('u5', '鼯
u6 Details
('u6', '有



ua1 Details
('ua1', '佤
('ua1', '呱
('ua1', '哇
('ua1', '娃
('ua1', '洼
('ua1', '瓦
('ua1', '蛙
('ua1', '蜗
ua2 Details
('ua2', '倚
('ua2', '我
ua7 Details
('ua7', '哇
('ua7', '嚄


uag8 Details
('uag8', '砉
('uag8', '获
('uag8', '騞



uah4 Details
('uah4', '喝
uah8 Details
('uah8', '嚄
('uah8', '活



uai1 Details
('uai1', '挖
('uai1', '歪
('uai1', '穵



uan1 Details
('uan1', '安
('uan1', '鞍
uan2 Details
('uan2', '碗
uan3 Details
('uan3', '晏
('uan3', '案
uan6 Details
('uan6', '旱
uan7 Details
('uan7', '换



uang1 Details
('uang1', '汪
('uang1', '薨
uang2 Details
('uang2', '往
('uang2', '枉
('uang2', '鲩
uang5 Details
('uang5', '元
('uang5', '凰
('uang5', '王
('uang5', '皇
('uang5', '蚖
('uang5', '蝗
uang6 Details
('uang6', '旺
('uang6', '王



ug4 Details
('ug4', '兀
('ug4', '嗢
('ug4', '尉
('ug4', '斡
('ug4', '杌
('ug4', '熨
('ug4', '腽
('ug4', '蔚
('ug4', '郁
('ug4', '靰
ug8 Details
('ug8', '夗



ui1 Details
('ui1', '偎
('ui1', '医
('ui1', '威
('ui1', '崴
('ui1', '煨
('ui1', '葳
('ui1', '衣
('ui1', '逶
('ui1', '隈
ui2 Details
('ui2', '伟
('ui2', '喂
('ui2', '委
('ui2', '洧
('ui2', '渭
('ui2', '炜
('ui2', '猥
('ui2', '猬
('ui2', '玮
('ui2', '痿
('ui2', '纬
('ui2', '苇
('ui2', '萎
('ui2', '诿
('ui2', '韦
('ui2', '韪
('ui2', '餧
ui3 Details
('ui3', '谓
ui5 Details
('ui5', '为
('ui5', '围
('ui5', '帏
('ui5', '桅
('ui5', '沩
('ui5', '涠
('ui5', '违
('ui5', '闱
('ui5', '韦
ui6 Details
('ui6', '欸
('ui6', '谓
ui7 Details
('ui7', '位
('ui7', '胃



uin3 Details
('uin3', '畏
('uin3', '碨



ung1 Details
('ung1', '榅
('ung1', '氲
('ung1', '温
('ung1', '瘟
('ung1', '蕰
('ung1', '酝
('ung1', '鳁
ung2 Details
('ung2', '䘼
('ung2', '愠
('ung2', '殒
('ung2', '稳
('ung2', '緼
('ung2', '缊
('ung2', '蕴
('ung2', '阮
('ung2', '韫
ung3 Details
('ung3', '揾
ung5 Details
('ung5', '云
('ung5', '匀
('ung5', '昀
('ung5', '涢
('ung5', '焚
('ung5', '畇
('ung5', '筠
('ung5', '纭
('ung5', '耘
('ung5', '芸
('ung5', '赟
('ung5', '郧
('ung5', '鋆
ung6 Details
('ung6', '陨
ung7 Details
('ung7', '云
('ung7', '运
('ung7', '郓
('ung7', '韵



uê1 Details
('uê1', '埚
('uê1', '锅
uê3 Details
('uê3', '刿
('uê3', '尉
('uê3', '慰
('uê3', '秽
('uê3', '蔚
uê6 Details
('uê6', '卫
uê7 Details
('uê7', '画
('uê7', '畫
('uê7', '话



uêg4 Details
('uêg4', '斡
('uêg4', '曰
uêg8 Details
('uêg8', '刖
('uêg8', '樾
('uêg8', '粤
('uêg8', '蚏
('uêg8', '越
('uêg8', '钺
('uêg8', '镬


uêh4 Details
('uêh4', '哕
('uêh4', '抉
uêh8 Details
('uêh8', '划
('uêh8', '劃
('uêh8', '婳
('uêh8', '画
('uêh8', '畫
('uêh8', '砉
('uêh8', '秽



uêng1 Details
('uêng1', '冤
('uêng1', '寃
('uêng1', '帵
('uêng1', '弯
('uêng1', '湾
('uêng1', '豌
('uêng1', '鸳
('uêng1', '鹓
uêng2 Details
('uêng2', '剜
('uêng2', '婉
('uêng2', '宛
('uêng2', '惋
('uêng2', '浣
('uêng2', '澣
('uêng2', '琬
('uêng2', '畹
('uêng2', '皖
('uêng2', '绾
('uêng2', '脘
('uêng2', '腕
('uêng2', '苑
('uêng2', '莞
('uêng2', '蜿
('uêng2', '踠
uêng3 Details
('uêng3', '怨
('uêng3', '掾
uêng5 Details
('uêng5', '丸
('uêng5', '员
('uêng5', '垸
('uêng5', '完
('uêng5', '椽
('uêng5', '橼
('uêng5', '湲
('uêng5', '烷
('uêng5', '猨
('uêng5', '猿
('uêng5', '缘
('uêng5', '芫
('uêng5', '袁
('uêng5', '辕



za1 Details
('za1', '吒
('za1', '咱
('za1', '喒
('za1', '喳
('za1', '嗟
('za1', '扎
('za1', '揸
('za1', '摣
('za1', '查
('za1', '楂
('za1', '槎
('za1', '樝
('za1', '渣
('za1', '溠
('za1', '猹
('za1', '皻
('za1', '碴
('za1', '茬
('za1', '馇
('za1', '齇
za2 Details
('za2', '怎
('za2', '早
('za2', '昔
('za2', '昨
za3 Details
('za3', '乍
('za3', '吒
('za3', '咋
('za3', '怍
('za3', '柞
('za3', '榨
('za3', '炸
('za3', '煠
('za3', '痄
('za3', '砟
('za3', '窄
('za3', '舴
('za3', '苲
('za3', '蚱
('za3', '诈
('za3', '鲊
('za3', '鲝



zab4 Details
('zab4', '匝
('zab4', '咂
('zab4', '唼
('zab4', '帀
('zab4', '扱
('zab4', '札
('zab4', '汁
('zab4', '沞
('zab4', '眨
('zab4', '砸
('zab4', '臜
zab8 Details
('zab8', '什
('zab8', '十
('zab8', '拾
('zab8', '杂
('zab8', '集



zag4 Details
('zag4', '作
('zag4', '岞
('zag4', '扎
('zag4', '拶
('zag4', '栉
('zag4', '疖
('zag4', '笮
('zag4', '紥
('zag4', '节
('zag4', '轧
('zag4', '铡
('zag4', '


zah4 Details
('zah4', '赍
zah8 Details
('zah8', '栅
('zah8', '炸
('zah8', '牐
('zah8', '闸
('zah8', '


zai1 Details
('zai1', '栽
('zai1', '灾
('zai1', '甾
('zai1', '知
zai2 Details
('zai2', '仔
('zai2', '宰
('zai2', '崽
('zai2', '滓
('zai2', '载
zai3 Details
('zai3', '再
('zai3', '载
zai5 Details
('zai5', '才
('zai5', '脐
zai6 Details
('zai6', '在
('zai6', '豸
zai7 Details
('zai7', '哉


zam1 Details
('zam1', '箴
('zam1', '簪
('zam1', '簮
('zam1', '针
zam2 Details
('zam2', '崭
('zam2', '斩
zam3 Details
('zam3', '湛
('zam3', '蘸
('zam3', '谮
zam6 Details
('zam6', '嵁
('zam6', '站
('zam6', '錾



zang1 Details
('zang1', '庄
('zang1', '曾
('zang1', '棕
('zang1', '椶
('zang1', '糌
('zang1', '脏
('zang1', '臜
('zang1', '臧
('zang1', '赃
('zang1', '騣
('zang1', '鬃
('zang1', '鬉
zang2 Details
('zang2', '总
('zang2', '拶
('zang2', '搃
('zang2', '攥
('zang2', '驵
zang3 Details
('zang3', '壮
('zang3', '壵
('zang3', '奘
('zang3', '攅
('zang3', '攒
('zang3', '昝
('zang3', '栈
('zang3', '瓒
('zang3', '粽
('zang3', '糉
('zang3', '缵
('zang3', '赞
('zang3', '趱
('zang3', '躜
('zang3', '钻
zang5 Details
('zang5', '丛
('zang5', '层
zang6 Details
('zang6', '脏
('zang6', '臧
('zang6', '藏
zang7 Details
('zang7', '赠



zao1 Details
('zao1', '糟
('zao1', '遭
zao2 Details
('zao2', '笊
('zao2', '蚤
('zao2', '走
zao3 Details
('zao3', '奏
('zao3', '灶
zao6 Details
('zao6', '唕
('zao6', '唣
('zao6', '悼
('zao6', '慥
('zao6', '櫂
('zao6', '淖
('zao6', '皁
('zao6', '皂
('zao6', '罩
('zao6', '造



ze1 Details
('ze1', '之
('ze1', '书
('ze1', '兹
('ze1', '卮
('ze1', '咨
('ze1', '嗞
('ze1', '姿
('ze1', '孜
('ze1', '孳
('ze1', '嵫
('ze1', '巵
('ze1', '淄
('ze1', '滋
('ze1', '粢
('ze1', '缁
('ze1', '芝
('ze1', '菑
('ze1', '訾
('ze1', '赀
('ze1', '资
('ze1', '赍
('ze1', '趑
('ze1', '辎
('ze1', '锱
('ze1', '镃
('ze1', '鲻
('ze1', '鹚
('ze1', '龇
ze2 Details
('ze2', '仔
('ze2', '子
('ze2', '梓
('ze2', '煑
('ze2', '煮
('ze2', '籽
('ze2', '訾
ze3 Details
('ze3', '恣
('ze3', '渍
('ze3', '眦
ze5 Details
('ze5', '茨
('ze5', '薯
('ze5', '藷
ze6 Details
('ze6', '自



zeng1 Details
('zeng1', '庄
('zeng1', '樟
('zeng1', '砖
('zeng1', '装
('zeng1', '赃
zeng2 Details
('zeng2', '指
zeng3 Details
('zeng3', '葬
('zeng3', '钻
zeng7 Details
('zeng7', '旋
('zeng7', '状



zi1 Details
('zi1', '卮
('zi1', '巵
('zi1', '膣
zi2 Details
('zi2', '只
('zi2', '咫
('zi2', '址
('zi2', '姉
('zi2', '姊
('zi2', '子
('zi2', '扺
('zi2', '指
('zi2', '旨
('zi2', '枳
('zi2', '止
('zi2', '沚
('zi2', '祇
('zi2', '祉
('zi2', '秭
('zi2', '稚
('zi2', '穉
('zi2', '笫
('zi2', '籽
('zi2', '紫
('zi2', '脂
('zi2', '芷
('zi2', '茝
('zi2', '衹
('zi2', '诣
('zi2', '趾
('zi2', '阯
('zi2', '霁
('zi2', '黹
zi3 Details
('zi3', '傺
('zi3', '制
('zi3', '剂
('zi3', '帜
('zi3', '志
('zi3', '挚
('zi3', '挤
('zi3', '掣
('zi3', '梽
('zi3', '济
('zi3', '炽
('zi3', '痣
('zi3', '瘵
('zi3', '祭
('zi3', '穄
('zi3', '胾
('zi3', '至
('zi3', '觯
('zi3', '识
('zi3', '贽
('zi3', '跻
('zi3', '际
('zi3', '韲
('zi3', '鸷
('zi3', '齑
zi5 Details
('zi5', '眵
('zi5', '粢
zi6 Details
('zi6', '巳
('zi6', '舐



zia1 Details
('zia1', '遮
zia2 Details
('zia2', '姐
('zia2', '毑
('zia2', '者
('zia2', '锗
zia3 Details
('zia3', '柘
('zia3', '炙
('zia3', '蔗
('zia3', '跖
('zia3', '蹠
('zia3', '鹧
zia6 Details
('zia6', '借
('zia6', '籍
('zia6', '褯
zia7 Details
('zia7', '谢



ziag4 Details
('ziag4', '勺
('ziag4', '嚼
('ziag4', '妁
('ziag4', '杓
('ziag4', '灼
('ziag4', '爵
('ziag4', '禚
('ziag4', '芍
('ziag4', '酌



ziah4 Details
('ziah4', '只
('ziah4', '摭
('ziah4', '脊
('ziah4', '迹
('ziah4', '隻
ziah8 Details
('ziah8', '食



zian1 Details
('zian1', '晶
('zian1', '正
('zian1', '精
zian2 Details
('zian2', '整
('zian2', '汫
zian3 Details
('zian3', '正
zian5 Details
('zian5', '情
('zian5', '成



ziang1 Details
('ziang1', '伥
('ziang1', '嫜
('ziang1', '将
('ziang1', '张
('ziang1', '彰
('ziang1', '樟
('ziang1', '漳
('ziang1', '獐
('ziang1', '璋
('ziang1', '章
('ziang1', '羴
('ziang1', '蟑
('ziang1', '麞
ziang2 Details
('ziang2', '赆
('ziang2', '长
ziang3 Details
('ziang3', '伥
('ziang3', '奖
('ziang3', '奨
('ziang3', '将
('ziang3', '嶂
('ziang3', '幛
('ziang3', '怅
('ziang3', '涨
('ziang3', '瘴
('ziang3', '糡
('ziang3', '糨
('ziang3', '胀
('ziang3', '障
ziang6 Details
('ziang6', '丈
('ziang6', '仗
('ziang6', '匠
('ziang6', '杖



zig4 Details
('zig4', '嵴
('zig4', '浙
('zig4', '炽
('zig4', '瘠
('zig4', '织
('zig4', '脊
('zig4', '蹐
('zig4', '鲫
('zig4', '鹡



zih4 Details
('zih4', '折
('zih4', '接
('zih4', '褶
('zih4', '詟
zih8 Details
('zih8', '折
('zih8', '舌



zim1 Details
('zim1', '吣
('zim1', '斟
('zim1', '箴
zim2 Details
('zim2', '枕
zim3 Details
('zim3', '浸



zin1 Details
('zin1', '吱
('zin1', '支
('zin1', '歧
('zin1', '毡
('zin1', '氊
('zin1', '氏
('zin1', '肢
('zin1', '脂
('zin1', '荐
('zin1', '酯
('zin1', '鞯
zin2 Details
('zin2', '稚
('zin2', '穉
zin3 Details
('zin3', '挤
('zin3', '煎
('zin3', '箭
zin5 Details
('zin5', '檐
('zin5', '簷
('zin5', '荠
('zin5', '钱



zing1 Details
('zing1', '嗔
('zing1', '榛
('zing1', '津
('zing1', '溱
('zing1', '獉
('zing1', '琎
('zing1', '璡
('zing1', '真
('zing1', '瞋
('zing1', '臻
('zing1', '蓁
('zing1', '薪
zing2 Details
('zing2', '拯
('zing2', '振
('zing2', '赈
('zing2', '震
zing3 Details
('zing3', '晋
('zing3', '牮
('zing3', '缙
('zing3', '荐
('zing3', '进
zing6 Details
('zing6', '尽
('zing6', '浕
('zing6', '荩
('zing6', '赆



ziu1 Details
('ziu1', '周
('ziu1', '啁
('ziu1', '州
('ziu1', '洲
('ziu1', '盩
('ziu1', '稠
('ziu1', '舟
('ziu1', '赒
('ziu1', '辀
('ziu1', '週
('ziu1', '鸼
ziu2 Details
('ziu2', '酒
ziu3 Details
('ziu3', '呪
('ziu3', '咒
('ziu3', '皱
ziu6 Details
('ziu6', '僦
('ziu6', '就
('ziu6', '鹫



ziê1 Details
('ziê1', '招
('ziê1', '椒
('ziê1', '蕉
ziê2 Details
('ziê2', '少
ziê3 Details
('ziê3', '曌
('ziê3', '照



ziêg4 Details
('ziêg4', '即
('ziêg4', '唧
('ziêg4', '晢
('ziêg4', '楶



ziêh4 Details
('ziêh4', '借
('ziêh4', '质
('ziêh4', '锧
ziêh8 Details
('ziêh8', '石



ziên1 Details
('ziên1', '浆
('ziên1', '章
ziên2 Details
('ziên2', '仉
('ziên2', '掌
('ziên2', '桨
('ziên2', '礃
('ziên2', '蒋
ziên3 Details
('ziên3', '糡
('ziên3', '糨
('ziên3', '酱
ziên6 Details
('ziên6', '上
('ziên6', '痒
ziên7 Details
('ziên7', '上



ziêng1 Details
('ziêng1', '戋
('ziêng1', '旃
('ziêng1', '枬
('ziêng1', '湔
('ziêng1', '溅
('ziêng1', '煎
('ziêng1', '笺
('ziêng1', '羴
('ziêng1', '羶
('ziêng1', '膻
('ziêng1', '轸
('ziêng1', '邅
('ziêng1', '鞯
('ziêng1', '饘
('ziêng1', '鳣
('ziêng1', '鹯
ziêng2 Details
('ziêng2', '戬
('ziêng2', '殄
('ziêng2', '溅
('ziêng2', '烬
('ziêng2', '畛
('ziêng2', '疹
('ziêng2', '稹
('ziêng2', '缜
('ziêng2', '翦
('ziêng2', '胗
('ziêng2', '诊
('ziêng2', '谫
('ziêng2', '趁
('ziêng2', '趂
('ziêng2', '践
('ziêng2', '饯
('ziêng2', '鬒
ziêng3 Details
('ziêng3', '剪
('ziêng3', '战
('ziêng3', '颤


zo1 Details
('zo1', '灾
('zo1', '糟
('zo1', '髽
zo2 Details
('zo2', '佐
('zo2', '俎
('zo2', '左
('zo2', '枣
('zo2', '阻
zo3 Details
('zo3', '作
('zo3', '做
zo5 Details
('zo5', '槽
('zo5', '漕
zo6 Details
('zo6', '助
('zo6', '唑
('zo6', '坐
('zo6', '状
('zo6', '造
zo7 Details
('zo7', '座



zog4 Details
('zog4', '嘱
('zog4', '属
('zog4', '瞩
('zog4', '祝
('zog4', '足
zog8 Details
('zog8', '族
('zog8', '簇
('zog8', '粥
('zog8', '蔟
('zog8', '蠋
('zog8', '镞
('zog8', '鷟



zoh4 Details
('zoh4', '作
zoh8 Details
('zoh8', '绝



zoi7 Details
('zoi7', '㩼



zoih4 Details
('zoih4', '节
zoih8 Details
('zoih8', '巀
('zoih8', '截



zoin2 Details
('zoin2', '指
zoin5 Details
('zoin5', '前
('zoin5', '齐



zong1 Details
('zong1', '宗
('zong1', '忪
('zong1', '枞
('zong1', '淙
('zong1', '琮
('zong1', '终
('zong1', '综
('zong1', '螽
('zong1', '踪
('zong1', '騣
zong2 Details
('zong2', '偬
('zong2', '总
('zong2', '种
('zong2', '踵
zong3 Details
('zong3', '众
('zong3', '纵



zou1 Details
('zou1', '租
('zou1', '诌
('zou1', '诹
('zou1', '邹
('zou1', '驺
('zou1', '鲰
zou2 Details
('zou2', '祖
zou6 Details
('zou6', '骤



zu1 Details
('zu1', '侏
('zu1', '咀
('zu1', '徂
('zu1', '朱
('zu1', '株
('zu1', '槠
('zu1', '橥
('zu1', '殂
('zu1', '洙
('zu1', '潴
('zu1', '狙
('zu1', '珠
('zu1', '疽
('zu1', '组
('zu1', '苴
('zu1', '茱
('zu1', '菹
('zu1', '葅
('zu1', '蛆
('zu1', '诅
('zu1', '诛
('zu1', '诸
('zu1', '趄
('zu1', '邾
('zu1', '铢
('zu1', '陬
('zu1', '雎
('zu1', '龃
zu2 Details
('zu2', '主
('zu2', '俎
('zu2', '拄
('zu2', '沮
('zu2', '砫
('zu2', '麈
zu3 Details
('zu3', '注
('zu3', '炷
('zu3', '疰
('zu3', '翥
('zu3', '蛀
('zu3', '蠧
('zu3', '蠹
('zu3', '铸
zu6 Details
('zu6', '住
('zu6', '炷
('zu6', '祚
('zu6', '聚
('zu6', '胙
('zu6', '酢
('zu6', '阼
('zu6', '驻



zua1 Details
('zua1', '抓
('zua1', '挝
zua2 Details
('zua2', '纸
zua5 Details
('zua5', '虵
('zua5', '蛇



zuag8 Details
('zuag8', '擢
('zuag8', '浊
('zuag8', '蜀
('zuag8', '镯



zuan1 Details
('zuan1', '煎
zuan2 Details
('zuan2', '盏
zuan5 Details
('zuan5', '泉
('zuan5', '鳈
zuan7 Details
('zuan7', '贱



zuang1 Details
('zuang1', '妆
('zuang1', '庄
('zuang1', '桩
('zuang1', '装
zuang3 Details
('zuang3', '赚
zuang6 Details
('zuang6', '僮
('zuang6', '噇
('zuang6', '撞
('zuang6', '状



zug4 Details
('zug4', '卒
('zug4', '帅
('zug4', '捽
('zug4', '摔
('zug4', '率
zug8 Details
('zug8', '秫
('zug8', '穤
('zug8', '糯



zuh4 Details
('zuh4', '嘬



zui1 Details
('zui1', '椎
('zui1', '濉
('zui1', '睢
('zui1', '锥
('zui1', '隹
('zui1', '骓
zui2 Details
('zui2', '水
zui3 Details
('zui3', '粹
('zui3', '醉
zui6 Details
('zui6', '悴
('zui6', '朘
('zui6', '淬
('zui6', '猝
('zui6', '瘁
('zui6', '祟
('zui6', '萃
('zui6', '赘



zung1 Details
('zung1', '尊
('zung1', '撙
('zung1', '樽
('zung1', '罇
('zung1', '衠
('zung1', '遵
('zung1', '鳟
zung2 Details
('zung2', '准
('zung2', '埻
('zung2', '隼
zung3 Details
('zung3', '俊
('zung3', '儁
('zung3', '圳
('zung3', '峻
('zung3', '浚
('zung3', '濬
('zung3', '竣
('zung3', '镌
('zung3', '隽
('zung3', '馂
('zung3', '骏
zung5 Details
('zung5', '舩
('zung5', '船
('zung5', '阵
zung6 Details
('zung6', '捘



zuê3 Details
('zuê3', '最
zuê6 Details
('zuê6', '罪
('zuê6', '辠
zuê7 Details
('zuê7', '襊



zuêg4 Details
('zuêg4', '叕
('zuêg4', '棁



zuêng1 Details
('zuêng1', '专
('zuêng1', '湍
('zuêng1', '遄
('zuêng1', '镌
('zuêng1', '颛
zuêng2 Details
('zuêng2', '啭
('zuêng2', '转
zuêng3 Details
('zuêng3', '攅
('zuêng3', '攒
zuêng6 Details
('zuêng6', '撰
('zuêng6', '馔



zê1 Details
('zê1', '斋
('zê1', '斎
zê2 Details
('zê2', '姐
('zê2', '赭
('zê2', '这
zê3 Details
('zê3', '债
zê7 Details
('zê7', '寨
('zê7', '砦



zêg4 Details
('zêg4', '则
('zêg4', '叔
('zêg4', '烛
('zêg4', '稷
('zêg4', '谡
('zêg4', '踖
zêg8 Details
('zêg8', '一
('zêg8', '壹
('zêg8', '弌
('zêg8', '泽
('zêg8', '蜀



zêh4 Details
('zêh4', '仄
('zêh4', '唶
('zêh4', '啧
('zêh4', '帻
('zêh4', '昃
('zêh4', '碛
('zêh4', '积
('zêh4', '箦
('zêh4', '绩
('zêh4', '职
('zêh4', '责
('zêh4', '迮



zên1 Details
('zên1', '争
zên2 Details
('zên2', '井
('zên2', '宑
('zên2', '肼
('zên2', '阱
zên5 Details
('zên5', '晴
zên6 Details
('zên6', '静



zêng1 Details
('zêng1', '丁
('zêng1', '侦
('zêng1', '僧
('zêng1', '噌
('zêng1', '增
('zêng1', '峥
('zêng1', '帧
('zêng1', '征
('zêng1', '怔
('zêng1', '憎
('zêng1', '挣
('zêng1', '曾
('zêng1', '桢
('zêng1', '浈
('zêng1', '烝
('zêng1', '狰
('zêng1', '琤
('zêng1', '甑
('zêng1', '盅
('zêng1', '睁
('zêng1', '睛
('zêng1', '矰
('zêng1', '祯
('zêng1', '筝
('zêng1', '精
('zêng1', '缯
('zêng1', '罾
('zêng1', '腈
('zêng1', '舂
('zêng1', '菁
('zêng1', '蒸
('zêng1', '诤
('zêng1', '贞
('zêng1', '钟
('zêng1', '钲
('zêng1', '铮
('zêng1', '锺
zêng2 Details
('zêng2', '种
('zêng2', '肿
zêng3 Details
('zêng3', '众
('zêng3', '政
('zêng3', '正
('zêng3', '症
('zêng3', '种
('zêng3', '証
('zêng3', '证
('zêng3', '蹭
('zêng3', '锃
zêng5 Details
('zêng5', '嶒
('zêng5', '曾
zêng6 Details
('zêng6', '净
('zêng6', '婧
('zêng6', '靓
('zêng6', '靖
