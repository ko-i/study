fn get_shortest<'a>(names: &'a Vec<&str>) -> Option<&'a str> {
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

fn get_shortest_length(names: &Vec<&str>) -> Option<usize> {
    match get_shortest(names) {
        Some(shortest) => Some(shortest.len()),
        None => None,
    }
}

fn main() {
    let vec = vec!["uku", "panny"];

    println!("{:?}", get_shortest_length(&vec));
    println!("{:?}", vec);

    println!("{:?}", get_shortest_length(&Vec::new()));
}