1. timedatectl set-ntp true
    a. timedatectl status
2. cfdisk 
    a. type: dos
    b. Partition size: YT: 30G / 32G   PERS: 4G 4G --> Change
    c. Primary
    d. Bootable --> New --> Primary --> Type Linux-Swap 
    e. write
    f. yes
    g. quit
        clear
3. mkfs.ext4 /dev/sda1
4. mkswap /dev/sda2
5. swapon /dev/sda2
6. mount /dev/sda1 /mnt
7. pacstrap /mnt base linux linux-firmware
    DW
8. genfstab -U /mnt >> /mnt/etc/fstab
9. arch-chroot /mnt
10. ln -sf /use/share/zoneinfo/America/Texas /etc/localtime
11. hwclock --systohc
12. pacman -S nano
    DW
13. pacman -S vim
    DW
14. nano /etc/locale.gen
    uncomment #en_US.UTF-8
    locale-gen ..done
    
15. nano /etc/hostname 
    DW fk // IZ
16. nano /etc/hosts
    127.0.0.1 tab localhost
    ::1     tab2x localhost
    127.0.1.1 fk.localdomain fk //IZ
17. passwd
    a. Enter PW
    b. reenter
18. useradd -m usrname
19. passwd usrname
    a. Enter PW
    b. reenter
20. pacman -S sudo
21. usermod -aG wheel,audo,video,optical,storage username
22. groups username
23. visudo
    a. delete "Uncomment to allow members of group wheel to execute aby command %wheel ALL=(ALL) ALL 
    b. :wq
24. pacman -S dhcpcd
25. systemctl enable dhcpcd
26. pacman -S grub
27. grub-install /dev/sda
28. grub-mkconfig -o /boot/grub/grub.cfg
29. sudo nano /etc/default/grub
    DW 
    a. GRUB-TIMEOUT=-1
    b. Save 
30. grub-mkconfig -o /boot/grub/grub.cfg
    Generating grub config file // Found Linux image: found initrd image: found fallback initrd image // done 
31. exit
32. shutdown now
33. unmount iso file
34. boot and pray 1:28:21