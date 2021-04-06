##  89C52RC-demo

```shell
sdcc your_location.c
packiph your_iph_file > your_hex.hex
stcgal -P stc89 -p /dev/tty.<your_port> <name.ihx>
```

**注意芯片如果不是89C52RC**: stcgal是无法烧制程序进入芯片的。

### 环境准备(Macos)
1. 下载CH34* USB 驱动 [下载地址](http://www.wch.cn/download/CH341SER_MAC_ZIP.html) 并安装，重启系统。
```shell script
ls /dev/tt.*
```
查看是否已经成功驱动上。

2. 安装sdcc环境 
```shell script
brew install sdcc
```

3. 安装stcgal
clone下相关地址 prev条件需要安装python2或者python3
```shell script
git clone https://github.com/grigorig/stcgal

cd stcgal
./setup.py build

sudo ./setup.py install
```

4. 编译Lib
```makefile
# /lib/Makefile

default-target: all

all:
		for n in $(LIB_DIRS); do cd $$n && make all && cd ..; done
```

5. 编译运行某个程序

进入相应目录查看Makefile文件来进行编译，亦可手动编译，但是前置条件需要把lib目录的相关先进行编译处理。

6. 串口通信

使用 [COMTool](https://github.com/Neutree/COMTool) 来进行测试。

### 基础
1. [点亮第一个LED](src/led)
2. [蜂鸣器](src/beep)
3. [继电器](src/relay)
4. [数码管](src/ds)
5. [独立按键](src/indbtn)
6. [组合按键](src/unibtn)
7. [IO扩展并转串](src/p2s)
8. [IO扩展串转并](src/s2p)
9. [LED矩阵](src/ledmatrix)
10. [五线四项步进电机](src/dcmotor)
11. [步进电机](src/steppingmotor)
12. [中断系统介绍](src/interrupt)
13. [外部中断](src/outinterrupt)
14. [定时器中断](src/timerinterrupt)
15. [ADC](src/adc)
16. [DAC](src/dac)
17. [串口通信](src/serial)
18. [LCD1602](src/lcd1602)