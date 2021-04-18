use std::iter::FromIterator;

fn main() {
    let mut outer = "Earth".to_string();
    let inner = String::from_iter(outer.drain(1..4));

    println!("{:?}", outer);
    println!("{:?}", inner);
}