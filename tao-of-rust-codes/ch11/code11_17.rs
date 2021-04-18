use std::thread;

fn main() {
    let mut s = "Hello".to_string();

    for _ in 0..3 {
        thread::spawn(move || {
            s.push_str(" Rust!");
        });
    }
}