use std::rc::Rc;

fn main() {
    let x = Rc::new("hello");

    let y = x.clone();
    println!("{:?}", y);

    let z = (*x).clone();
    println!("{:?}", z);
}