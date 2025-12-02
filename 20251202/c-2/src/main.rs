use std::io::{self, Read};

fn main() {
    let mut _n  = String::new();
    io::stdin().read_line(&mut _n).unwrap();  
    let _n : usize = _n.trim_end().parse().unwrap();

    let mut a_list = String::new();
    io::stdin().read_line(&mut a_list).unwrap();
    let a_list : Vec<i64> = a_list.split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    //println!("n = {}", n);
    //println!("a = {:?}", a_list);

    //let mut loop_count: usize = 1;
    //let mut tmp_even: i64 = -1;

    //O(N^2)
    //for a in &a_list {
    //    for b in &a_list[loop_count..] {
    //        let c = a + b;
    //        if c % 2 == 0 && c > tmp_even {
    //            tmp_even = c;
    //        }
    //    }
    //    loop_count += 1;
    //}

    let mut evens: Vec<i64> = Vec::new();
    let mut odds: Vec<i64> = Vec::new();

    //O(N)
    for a in &a_list {
        if a % 2 == 0 {
            evens.push(*a);
        } else {
            odds.push(*a);
        }
    }

    // O(N log N)
    evens.sort_by(|a, b| b.cmp(a));
    odds.sort_by(|a, b| b.cmp(a));

    let mut max_even: i64 = -1;

    if evens.len() >= 2 {
        max_even = max_even.max(evens[0] + evens[1]);
    }
    if odds.len() >= 2 {
        max_even = max_even.max(odds[0] + odds[1]);
    }
    println!("{}", max_even);
}
