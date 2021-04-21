use std::collections::HashMap;

fn main() {
    let a = 2147483647;
    println!("{:p}", &a);
    println!("{:x}", a);

    let mut map = HashMap::new();
    map.insert("foo", "bar");
    println!("{:#?}", map);
}