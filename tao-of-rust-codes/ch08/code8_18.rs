fn main() {
    let bananas = "bananas";

    println!("{:?}", bananas.contains('a'));
    println!("{:?}", bananas.contains("an"));
    println!("{:?}", bananas.contains(char::is_lowercase));
    println!("{:?}", bananas.starts_with('b'));
    println!("{:?}", bananas.ends_with("nana"));
}