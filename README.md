# robosys2020_devicedriver
*ロボットシステム学の演習で作成、改良を行ったデバイスドライバのコード。*

## 実装内容
*講義内で作成したデバイスドライバに変更を加え、以下の機能を追加した。*
- 2を入力した場合、LEDの点灯と消灯を1セットとしてLEDが10セット点滅。
- 1を入力した場合、LEDが点灯。
- 0を入力した場合、LEDが消灯。

## 用意するもの
- Raspberry Pi 4 Model B
- ブレッドボード
- LED ×1
- 抵抗100Ω ×1
- ジャンパー戦(オス―メス) 2本

## 回路構成
*以下のように回路を組む。*
![robosys2020_devicedriver](https://user-images.githubusercontent.com/75324321/102012465-f2e97000-3d8d-11eb-9e68-6fa9dde1b6f1.jpg)
*LEDのアノード側をGPIO25に接続、カソード側を任意のGNDに接続。*
## 実行コマンド
1. このリポジトリをクローンする。
```
$ git clone https://github.com/momokohara/robosys2020_devicedriver.git

```
2.　ビルド
```
$ cd robosys2020/myled 
$ make
$ sudo insmod myled.ko
$ sudo chmod 666 /dev/myled0
```
*$ sudo insmod myled.koでカーネルモジュールをインストール
$ sudo chmod 666 /dev/myled0でファイルのアクセス権を変更*
3.　実行
#### 2を実行
```
$ echo 2 > /dev/myled0
```
#### 1を実行
```
$ echo 1 > /dev/myled0
```
#### 0を実行
```
$ echo 0 > /dev/myled0
```
*実行後は以下のコマンドを入力*
```
$ sudo rmmod myled
$ make clean
```
*$ sudo rmmod myledでカーネルモジュールのアンインストール
$ make cleanでカーネルモジュールを消去*
## デモ動画
*デモ動画のリンクは[こちら](https://youtu.be/eBIpdAT1aKY)。*

