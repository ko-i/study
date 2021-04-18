fn main() {
    let mut message = "Hello".to_string();

    message.extend(&[' ', 'R', 'u', 's', 't']);

    println!("{:?}", message);
}