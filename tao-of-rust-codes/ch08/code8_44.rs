fn main() {
    let s = [0, 1, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55];

    println!("{:?}", s.binary_search(&13));
    println!("{:?}", s.binary_search(&4));

    let r = s.binary_search(&1);
    println!("{:?}", match r {
        Ok(1..=3) => true,
        _ => false,
    });

    let seek = 13;
    println!("{:?}", s.binary_search_by(|probe| probe.cmp(&seek)));

    let s = [(0, 0), (2, 1), (4, 1), (5, 1), (3, 1), (1, 2), (2, 3), (4, 5), (5, 8), (3, 13), (1, 21), (2, 34), (4, 55)];

    println!("{:?}", s.binary_search_by_key(&13, |&(_a, b)| b), );
}