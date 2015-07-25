# 国科大2014级计算机C语言03班 - 习题参考 #

部分代码选取自做的比较好的童鞋的作业（已标注），供大家参考。如有bug，欢迎大家拍砖。

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

* 题1-浮点数判定 - `src/isfloat`

* 题2-元音统计 - `src/aoe(啊喔呃)` (ZHU Tianyao)

* 题3-日期格式化 - `src/datefmt`

* 题4-四阶幻方 - `src/msquare`

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

* 题1-字母计数之数组 - `src/letterc`

* 题2-字母计数之链表 - `src/lcount`

* 题3-单向链表逆序 - `src/rlist`

* 题4-交叉引用与排序 - `lan_DirectAndClear_f4.c` in our QQ group

## 第七次作业 - 0530 ##

* 题1-字符串加密 - `src/strenc`

* 题2-数字排列 - `src/abc123`

* 题3-NxN表格 - `src/nxn`

* 题4-口令字符串加密 - `src/pwdenc` (WANG Lei)

# 关于git #

虽然`github.com`中的代码可以直接Web浏览与下载，比如下载全部代码包可以[点我](https://github.com/qzan9/PPPuC03/archive/master.zip)，但建议感兴趣的童鞋学一下git。git是Linus Torvalds的第二个开源作品，是一个分布式版本控制工具。这坨代码就是用git管的，比如在Ubuntu下：

```
    sudo apt-get install git
    git clone https://github.com/qzan9/pppuc03.git
```

下载完后就可以去`pppuc03`目录中读代码了。今后代码库有了更新，可以在`pppuc03`目录下直接敲命令：

```
    git pull origin master
```

来“拉”新代码。

当然也欢迎大家向我`push`代码；作业虽然简单，但写得精致点并分享出来，对学习还是很有帮助的。

# 关于make #

代码库中包含了`Makefile`，在`pppuc03`目录下键入`make`即可编译，编译得到的可执行文件默认保存到了`bin`目录下。

感兴趣的童鞋也可以学一下make，make是一个build管理工具；M$ VS的解决方案、工程项目等的东西，可以看作是make的图形化。

另：四阶幻方如需编译OpenMP，`make omp=1`即可。

# 关于VS #

代码库中包含了Visual Studio的工程文件，Windows下双击`pppuc03.sln`即可打开；我使用的VS版本为2010。

另：编译OpenMP需要`vcomp.lib`静态库（[点我下载](http://pan.baidu.com/s/1590Ai)），运行需要`vcomp90.dll`动态库（[点我下载](http://pan.baidu.com/s/1eQJExmq)）。

![四阶幻方OMP](http://7xk0df.com1.z0.glb.clouddn.com/msquare.png)

