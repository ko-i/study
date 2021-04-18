fn main() {
    let left = "the tao".to_string();
    let mut right = "Rust".to_string();

    println!("{:?}", left + " of " + &right);

    right += "!";
    println!("{:?}", right);
}