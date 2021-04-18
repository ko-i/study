use std::thread;

fn main() {
    let mut x = vec![1, 2, 3, 4];
    thread::spawn(|| {
        x.push(1);
    });

    x.push(2);
}