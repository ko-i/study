fn get_shortest(names: Vec<&str>) -> Option<&str> {
    if names.len() > 0 {
        let mut shortest = names[0];

        for name in names.iter() {
            if name.len() < shortest.len() {
                shortest = *name;
            }
        }

        Some(shortest)
    } else {
        None
    }
}

fn show_shortest(names: Vec<&str>) -> &str {
    // get_shortest(names).unwrap()
    get_shortest(names).unwrap_or("Not found.")
    // get_shortest(names).unwrap_or_else(|| "Not found.")
    // get_shortest(names).expect("Not found")
}

fn main() {
    println!("{:?}", show_shortest(vec!["uku", "felipe"]));
    println!("{:?}", show_shortest(Vec::new()));
}