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

fn get_shortest_length(names: Vec<&str>) -> Option<usize> {
    get_shortest(names).map(|name| name.len())
}

fn main() {
    println!("{:?}", get_shortest_length(vec!["uku", "panny"]));
    println!("{:?}", get_shortest_length(Vec::new()));
}