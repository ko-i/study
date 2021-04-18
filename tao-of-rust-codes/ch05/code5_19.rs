fn main() {
    let s = "hello".to_string();
    let join = |i: &str| {s + i};
    assert_eq!("hello world", join(" world"));

    // println!("{:?}", s);
}