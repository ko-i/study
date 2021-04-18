use std::thread;

fn main() {
    let x = vec![1, 2, 3, 4];
    thread::spawn(|| x);
}