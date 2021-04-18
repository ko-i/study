fn main() {
    let id = "Iterator";

    println!("{:?}", id.chars().any(char::is_uppercase));
    println!("{:?}", id.chars().all(char::is_uppercase));
}