fn main() {
    let x = "1";
    let int_x: i32 = x.parse().unwrap();
    assert_eq!(int_x, 1);
}