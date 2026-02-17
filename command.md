## --- 1. ファイル操作 (Navigation & Management) ---

ls          # ファイル一覧を表示 (list)
ls -F       # 種類がわかるように表示 (ディレクトリには / 実行ファイルには * がつく)
mkdir abc001
cd abc001
touch b.cpp # 空のファイルを作成
cp a.cpp b.cpp
mv b.cpp d.cpp
rm main.exe

 code 401.cpp
 code test.cpp
 code README.md

# --- 2. コンパイルと実行 (The Core Workflow) ---

g++ -O3 a.cpp -o a.out

# 実行ファイルに in.txt の中身を流し込む (標準入力のリダイレクト)

./a.out < in.txt

# 実行結果を out.txt に保存する (標準出力のリダイレクト)

./a.out < in.txt > out.txt

# --- 3. テキスト処理・確認 (Inspection) ---

cat in.txt
head -n 5 in.txt
tail -n 5 in.txt
wc -l in.txt    # 行数をカウント (word count -line) 入力行数の確認に。
grep "vector" a.cpp # a.cpp の中で "vector" を使っている行を検索

# --- 4. 比較と検証 (Verification) ---

diff out.txt ans.txt

# --- 5. 応用：Unix哲学（パイプ） ---

# 「a.out の出力を、そのまま次のコマンドに渡す」

# 例：出力の行数だけ数える

./a.out < in.txt | wc -l

# --- 6. 効率化 (Environment) ---

history
alias compile='g++ -O3 a.cpp -o a.out'
pwd

# パッケージリストの更新

sudo apt update

# C++のコンパイルに必要な基本セット（gcc, g++, makeなど）を一括インストール

sudo apt install build-essential

# ついでに競プロでよく使うツールも入れておく（任意）

sudo apt install gdb python3 python3-pip

g++ test.cpp -o test
./test

touch a.cpp
code a.cpp
echo "" > a.cpp  > は新規作成、>> は追記
