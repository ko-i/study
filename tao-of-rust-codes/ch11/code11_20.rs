use std::thread;
use std::sync::Arc;
use std::cell::RefCell;

fn main() {
    let s = Arc::new(RefCell::new("Hello".to_string()));

    for _ in 0..3 {
        let s_clone = s.clone();

        thread::spawn(move || {
            let s_clone = s_clone.borrow_mut();
            s_clone.push_str(" world!");
        });
    }
}