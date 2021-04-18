fn main() {
    let s = String::from("fooåbar");
    let s: String = s.chars().enumerate().map(|(i, c)| {
        if i % 2 == 0 {
            c.to_lowercase().to_string()
        } else {
            c.to_uppercase().to_string()
        }
    }).collect();

    println!("{:?}", s);
}