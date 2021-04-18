fn main() {
    let s = "hello".to_string();
    let c = || s;

    c();

    // c();
    // println!("{:?}", s);
}