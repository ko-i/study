use std::rc::Rc;
use std::sync::Arc;

fn main() {
    let r = Rc::new("Rust".to_string());
    let a = Arc::new(vec![1.0, 2.0, 3.0]);

    let x = *r;
    println!("{:?}", r);

    let f = *foo;

}