# 国科大计算机C语言03 - 习题参考 #

主要选取了做的比较好的童鞋的作业，供大家参考，顺带膜拜诸C霸C神 :-)

# 代码说明 #

## 第一次作业 - 0411 ##

题3-回文判定 - src/huiwen
题4-递归求幂 - src/power
题5-大整数相乘 - src/longmul

## 第二次作业 - 0418 ##

题2-Nth - src/nth
题3-递归回文判定 - src/palindrome

## 第三次作业 - 0425 ##

# 关于git #

github中的代码可以直接Web浏览；感兴趣的童鞋可以学一下git，这坨代码是用git管的。

比如Ubuntu下可以：

```
    sudo apt-get install git
    git clone https://github.com/qzan/ctests.git
```

下载完就可以去当前目录下的`ctests`中看代码了；下次有了代码更新，可以直接敲命令：

```
    git pull origin master
```

来更新代码。注意`git pull`之前需要先`cd`到`ctests`目录下。

# 关于make #

代码库中包含了`Makefile`，在`ctests`目下键入`make`即可编译。

默认的设定是编译得到的可执行文件保存到`bin`目录下。

感兴趣的童鞋可以学一下`make`。

