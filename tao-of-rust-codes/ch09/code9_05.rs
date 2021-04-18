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
    match get_shortest(names) {
        Some(shortest) => shortest,
        None => "Not found",
    }
}

fn main() {
    println!("{:?}", show_shortest(vec!["uku", "felipe"]));
    println!("{:?}", show_shortest(Vec::new()));
}