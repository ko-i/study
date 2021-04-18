fn main() {
    let upper_case: String = "große".chars()
        .inspect(|c| println!("before: {:?}", c))
        .flat_map(|c| c.to_uppercase())
        .inspect(|c| println!(" after:    {:?}", c))
        .collect();

    println!("{:?}", upper_case);   
}