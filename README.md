##  普中单片机学习代码

```shell
sdcc your_location.c
packiph your_iph_file > your_hex.hex
stcgal -P stc89 -p /dev/tty.<your_port> <name.ihx>
```

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

### 环境区别
头文件 sdcc 为<8051.h>或<8052.h> 在windows keil中为<reg51.h>和<reg52.h>

IO端口定义为 P2_0 而windows keil为 P2^0

IO口定义 `#define LED P2_0` keil为 `sbit LED = P2^0`

中断函数 `void INT0_ISR() __interrupt 0` keil为`void INT0_ISR() interrupt`

### 基础
1. 点亮第一个LED -> [code](./src/basic/led/README.md)
2. 蜂鸣器 -> [code](./src/basic/beep/README.md)
3. 继电器 -> [code](./src/basic/relay/README.md)
4. 数码管 -> [code](./src/basic/ds/README.md)
5. 独立按键 -> [code](./src/basic/indbtn/README.md)
6. 组合按键 -> [code](./src/basic/unibtn/README.md)