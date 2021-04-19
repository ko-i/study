use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();
    map.insert("one", 1);
    map.insert("two", 2);

    let incremented_value = match map.get("one") {
        Some(val) => val + 1,
        None => 0,
    };

    let incremented_value = if let Some(val) = map.get("one") {
        val + 1
    } else {
        0
    };

    println!("{}", incremented_value);
}