use std::thread;
use std::sync::Arc;

fn main() {
    let s = Arc::new("Hello".to_string());

    for _ in 0..3 {
        let s_clone = s.clone();

        thread::spawn(move || {
            s_clone.push_str(" world");
        });
    }
}