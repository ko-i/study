// use std::ascii::AsciiExt;

fn main() {
    let s = String::from("fooåbar");
    let mut result = s.into_bytes();

    (0..result.len()).for_each(|i|
        if i % 2 == 0 {
            result[i] = result[i].to_ascii_lowercase();
        } else {
            result[i] = result[i].to_ascii_uppercase();
        });

    println!("{:?}", String::from_utf8(result).unwrap());
}