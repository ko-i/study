fn main() {
    let precompute = {
        let a = (-34i64).abs();
        let b = 345i64.pow(2);
        let c = 3;
        a + b + c
    };

    let result_msg = match precompute {
        42 => "done",
        a if a % 2 == 0 => "continue",
        _ => panic!("oh no!")
    };

    println!("{}", result_msg);
}