use std::thread;
use std::rc::Rc;

fn main() {
    let mut s = Rc::new("Hello".to_string());

    for _ in 0..3 {
        let mut s_clone = s.clone();

        thread::spawn(move || {
            s_clone.push_str(" Rust");
        });
    }
}