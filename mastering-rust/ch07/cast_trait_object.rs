use std::fmt::Display;

fn show_me(item: &Display) {
    println!("{}", item);
}

fn main() {
    let a = "hello".to_string();
    let b = &a;
    show_me(b);
}