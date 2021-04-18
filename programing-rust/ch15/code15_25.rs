use std::collections::HashMap;

fn main() {
    let mut populations = HashMap::new();

    populations.insert("Portland", 583776);
    populations.insert("Fossil", 449);
    populations.insert("Greenhorn", 2);
    populations.insert("Boring", 7762);
    populations.insert("The Dalles", 15340);

    println!("{:?}", populations.iter().max_by_key(|&(_name, pop)| pop));
    println!("{:?}", populations.iter().min_by_key(|&(_name, pop)| pop));
}