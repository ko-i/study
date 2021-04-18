use std::thread;
use std::rc::Rc;

fn main() {
    let x = Rc::new(vec![1, 2, 3, 4]);

    thread::spawn(move || {
        x[1];
    });
}