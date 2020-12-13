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
*LEDのアノード側をGPIO25に接続、カソード側を任意のGNDに接続。*

## 環境構築
```
$ git clone https://github.com/momokohara/robosys2020_devicedriver.git

```
## ビルド
```
$ cd robosys2020/myled 
$ make
$ sudo insmod myled.ko
$ sudo chmod 666 /dev/myled0
```

## 実行結果
#### 2を実行
```
$ echo 2 > /dev/myled0
```
*以下のように動作する*

#### 1を実行
```
$ echo 1 > /dev/myled0
```
*以下のように動作する*

#### 0を実行
```
$ echo 0 > /dev/myled0
```
*以下のように動作する*

## デモ動画

## ライセンス
