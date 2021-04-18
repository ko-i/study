use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();

    map.insert("Portland", (45.5237606, -122.6819273));
    map.insert("ShangHai", (25.0375167, 121.5637));

    println!("{:?}", map);
    println!("{:#?}", map);
}