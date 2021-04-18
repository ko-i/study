fn main() {
    let x = "1";
    assert_eq!(x.parse::<i32>().unwrap(), 1);
}