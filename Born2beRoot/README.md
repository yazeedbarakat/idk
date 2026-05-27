*This activity has been created as part of the 42 curriculum by ybarakat.*

# Born2beRoot

## Description

Born2beRoot is a system administration project from the 42 curriculum. The goal is to set up a secure Linux server inside a virtual machine following strict rules. The project covers virtualization, disk partitioning with encryption, user and group management, firewall configuration, SSH hardening, password policies, sudo configuration, and system monitoring scripting.

By the end of this project, you will have a fully configured headless Debian server running inside VirtualBox with encrypted LVM partitions, a hardened SSH service, UFW firewall, AppArmor, strict password and sudo policies, and an automated monitoring script running via cron.

## Instructions

### Requirements
- VirtualBox 7.1 or later
- Debian 13 (Trixie) ISO

### Setup
1. Create a VM in VirtualBox with at least 12GB disk, 1024MB RAM, 1 CPU
2. Boot from the Debian ISO and follow the installer
3. During partitioning select "Guided - use entire disk and set up encrypted LVM"
4. Select "Separate /home partition"
5. Do not install any desktop environment — only SSH server and standard system utilities
6. After installation, configure the system following the steps below

### Configuration steps
1. **SSH** — Edit `/etc/ssh/sshd_config`, set `Port 4242` and `PermitRootLogin no`, restart SSH
2. **UFW** — Install ufw, set default deny incoming, allow port 4242, enable
3. **AppArmor** — Already installed on Debian, verify with `aa-status`
4. **Password policy** — Edit `/etc/login.defs` and `/etc/security/pwquality.conf`
5. **sudo** — Install sudo, create `/etc/sudoers.d/sudo_config` with strict rules
6. **Users/Groups** — Create `user42` group, add your user to `sudo` and `user42`
7. **monitoring.sh** — Create the script at `/usr/local/bin/monitoring.sh`
8. **Cron** — Add `*/10 * * * * /usr/local/bin/monitoring.sh` to root's crontab

### Generating the signature
```bash
# On Linux:
sha1sum ~/VirtualBox\ VMs/ybarakat42/ybarakat42.vdi
```
Paste the output into `signature.txt` at the root of your repository.

## Project Description

### Operating System Choice: Debian

Debian was chosen over Rocky Linux for this project for several reasons. Debian is more beginner-friendly for system administration, has extensive documentation, and uses APT which is simpler to work with than DNF/RPM. AppArmor, which Debian uses by default, is easier to configure than SELinux. Rocky Linux is an enterprise-grade RHEL clone that requires more advanced knowledge, especially for SELinux configuration.

**Debian advantages:** stable, well documented, large community, simpler setup
**Debian disadvantages:** slower to adopt new packages, less enterprise-focused

**Rocky advantages:** enterprise-grade, RHEL-compatible, SELinux is more powerful
**Rocky disadvantages:** complex setup, SELinux is harder to configure, smaller community

### AppArmor vs SELinux

Both are Mandatory Access Control (MAC) systems that restrict what programs can do.

**AppArmor** works with file paths — you define profiles per application specifying what files and resources it can access. It is simpler to configure and understand. Used by default on Debian and Ubuntu.

**SELinux** works with labels — every file, process and user has a security label and access is determined by policy rules between labels. It is more granular and powerful but significantly more complex to configure and troubleshoot. Used by default on RHEL, Fedora, and Rocky Linux.

For this project, AppArmor is sufficient and appropriate.

### UFW vs firewalld

Both are firewall management tools.

**UFW (Uncomplicated Firewall)** is designed to be simple and easy to use. Commands are straightforward (`ufw allow 4242`). Default on Debian/Ubuntu. Good for servers with simple firewall needs.

**firewalld** uses the concept of zones — network interfaces are assigned to zones with different trust levels. More flexible for complex network setups. Default on Fedora, RHEL, and Rocky Linux.

For this project, UFW is used on Debian. Rocky would require firewalld.

### VirtualBox vs UTM

**VirtualBox** is a free, open-source Type 2 hypervisor by Oracle. Works on Windows, Linux, and macOS (Intel). Uses hardware virtualization extensions (VT-x/AMD-V) for near-native performance. Well documented and widely used.

**UTM** is a virtualization app for macOS built on QEMU. Required on Apple Silicon (M1/M2) Macs because VirtualBox does not support ARM architecture. Supports both emulation and virtualization.

For this project, VirtualBox was used on a Fedora Linux host.

## Resources

- [Debian Documentation](https://www.debian.org/doc/)
- [UFW Documentation](https://help.ubuntu.com/community/UFW)
- [AppArmor Documentation](https://gitlab.com/apparmor/apparmor/-/wikis/Documentation)
- [Linux PAM Documentation](http://www.linux-pam.org/Linux-PAM-html/)
- [Cron manual](https://man7.org/linux/man-pages/man5/crontab.5.html)
- [SSH hardening guide](https://www.ssh.com/academy/ssh/sshd_config)

### AI Usage

Claude (claude.ai) was used as a learning companion throughout this project. It was used to understand concepts (virtualization, LVM, encryption, PAM, AppArmor, cron) before implementing them, to troubleshoot errors during setup, and to help structure the monitoring.sh script. All commands were run and verified manually — AI was not used to blindly copy solutions but to understand what each step does and why.
