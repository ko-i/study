use std::borrow::Cow;

fn get_name_1() -> String {
    std::env::var("USER").unwrap_or("Whoever you are".to_string())
}

fn get_name_2() -> Cow<'static, str> {
    std::env::var("USER").map(|v| Cow::Owned(v)).unwrap_or(Cow::Borrowed("Whoever you are"))
}

fn main() {
    println!("Greetings, {:?}!", get_name_1());
    println!("Greetings, {:?}!", get_name_2());
}