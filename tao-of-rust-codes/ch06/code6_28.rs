fn main() {
    let env_var = 1;

    let c = || env_var + 2;

    println!("{:?}", c());
}