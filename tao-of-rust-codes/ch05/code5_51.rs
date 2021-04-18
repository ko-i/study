use std::rc::Rc;

fn main() {
    let x = Rc::new(45);

    let y1 = x.clone();
    let y2 = x.clone();
    println!("{:?}", Rc::strong_count(&x));

    let w = Rc::downgrade(&x);
    println!("{:?}", Rc::weak_count(&x));

    let y3 = &*x;
    println!("{:?}", 100 - *x);
}