use std::collections::HashMap;

fn main() {
    let mut map: HashMap<&str, u32> = HashMap::new();

    map.entry("current_year").or_insert(2017);
    println!("{:?}", map["current_year"]);

    *map.entry("current_year").or_insert(2017) += 10;
    println!("{:?}", map["current_year"]);

    let last_leap_year = 2016;
    map.entry("next_leap_year").or_insert_with(|| last_leap_year + 4);
    println!("{:?}", map["next_leap_year"]);

    println!("{:?}", map.entry("current_year").key());
}