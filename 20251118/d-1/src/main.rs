use std::io::{self, Read};

fn main() {
    
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();  // ここで Enter まで読む
    let s = s.trim_end().as_bytes();         // 改行を除去して使う

    let n = s.len();
    let a = s;

    // 右側の頻度を初期化
    let mut right = [0i64; 26];
    for &ch in a {
        right[(ch - b'A') as usize] += 1;
    }

    let mut left = [0i64; 26];
    let mut ans: i64 = 0;

    for &ch in a {
        let m = (ch - b'A') as usize;
        // j は中央なので右カウントから除外
        right[m] -= 1;
        // 各文字 c について left[c] * right[c] を加算
        for c in 0..26 {
            ans += left[c] * right[c];
        }
        // j を左側に移す
        left[m] += 1;
    }

    println!("{}", ans);
}

