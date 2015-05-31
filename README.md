# 国科大2014级计算机C语言03 - 习题参考 #

主要选取了做的比较好的童鞋的作业，稍作修改（或不改），供大家参考。如有错误，欢迎大家拍砖。

# 代码说明 #

## 第一次作业 - 0411 ##

* 题1-sin与cos - `src/trig` (KONG Jing)

* 题2-算税 - `src/tax`

* 题3-回文判定 - `src/huiwen` (CHEN Yubi)

* 题4-递归求幂 - `src/power`

* 题5-大整数相乘 - `src/longmul`

## 第二次作业 - 0418 ##

* 题1-向量积 - `src/vector3d`

* 题2-Nth - `src/nth`

* 题3-递归回文 - `src/palindrome`

* 题4-四整数最大最小 - `src/minmax4` (KONG Jing)

* 题5-十进制转八进制 - `src/dec2oct`

## 第三次作业 - 0425 ##

* 题1-浮点数判定 - *待更新…*

* 题2-元音统计 - `src/aoe(啊喔呃)` (ZHU Tianyao)

* 题3-日期格式 - *待更新…*

* 题4-四阶幻方 - *待更新…*

## 第四次作业 - 0511 ##

* 题1-strstr - `src/strstr`

* 题2-head - `src/head` (ZHU Tianyao)

* 题3-“1”的个数 - `src/numof1` (KONG Jing)

* 题4-大数字显示 - `src/bigdigit` (ZHU Tianyao)

## 第五次作业 - 0516 ##

* 题1-两点距离 - `src/dist`

* 题2-完全数 - `src/perfnum` (LAN Qingfeng)

* 题3-添加参数 - `Unit11_studentscore.c` in our QQ group

* 题4-最长回文子串 - `src/subpal` (check [LeetCode](http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html))

## 第六次作业 - 0523 ##

* 题1-字母计数之数组 - *待更新*

* 题2-字母计数之链表 - *待更新*

* 题3-单向链表逆序 - *待更新*

* 题4-交叉引用与排序 - *待更新*

# 关于git #

虽然`github.com`中的代码可以直接Web浏览与下载，比如下载全部代码包可以[点我](https://github.com/qzan/PPPuC03/archive/master.zip)，但建议感兴趣的童鞋学一下git。git是Linus Torvalds的第二个开源作品，是一个分布式版本控制工具。这坨代码就是用git管的，比如在Ubuntu下：

```
    sudo apt-get install git
    git clone https://github.com/qzan/pppuc03.git
```

下载完后就可以去`pppuc03`目录中读代码了。

这样今后有了更新，可以在`pppuc03`目录下直接敲命令：

```
    git pull origin master
```

来“拉”新代码。

当然也欢迎大家向我`push`代码，作业虽然简单，但写得精致点并分享出来，对学习还是很有帮助的。

# 关于make #

代码库中包含了`Makefile`，在`pppuc03`目录下键入`make`即可编译，编译得到的可执行文件默认保存到了`bin`目录下。

感兴趣的童鞋也可以学一下make，make是一个build管理工具；M$ VS的解决方案、工程项目等的部分，可以看作是make的图形化。

