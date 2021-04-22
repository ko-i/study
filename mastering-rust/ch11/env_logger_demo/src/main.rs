use log::debug;

use user_auth::User;

fn main() {
    std::env::set_var("RUST_LOG", "user_autn=info,env_logger_demo=info cargo run");
    env_logger::init();
    debug!("env logger demo started");
    let user = User::new("bob", "super_serket");
    user.sign_in("super_secret");
    user.sign_in("super_serket");
}
