fn main() {
    let a = Box::new("hello");
    let b = Box::new("Rust".to_string());

    let c = *a;
    let d = *b;

    println!("{:?}", *a);
    println!("{:?}", a);
    // println!("{:?}", b);
    println!("{:?}", c);
    println!("{:?}", d);
}