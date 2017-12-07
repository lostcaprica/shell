#include <stdio.h>

#define  BUFF_SIZE   1024

int main( void)
{
   const char  *pname = "dmidecode -t 1 | grep Name | sed 's/\t//g'";
   const char  *serial = "dmidecode -t 1 | grep Serial | sed 's/\t//g'";
   const char  *cpuname = "cat /proc/cpuinfo | grep \"model name\" | sort -u | cut -f 2 -d :";
   const char  *cpucore = "cat /proc/cpuinfo | grep \"processor\" | cut -f 2 -d : | wc -l";
   const char  *cpuphy = "cat /proc/cpuinfo | grep \"physical id\" |sort -u | cut -f 2 -d : | sed 's/ //g' | wc -l";
   const char  *cpumhz = "cat /proc/cpuinfo | grep \"cpu MHz\" |sort -u | cut -f 2 -d : | sed 's/ //g'";
   const char  *memtotal = "cat /proc/meminfo | grep MemTotal";
   const char  *kernelv = "uname -a | awk '{print $3}'";
   const char  *kernelr = "uname -a | awk '{print $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15}'";
   const char  *ifconfig = "ifconfig | grep -e Ethernet -e  \"inet addr\" -e Local";
   const char  *ethtool = "ls /etc/sysconfig/network-scripts/ | grep ifcfg | cut -f 2 -d \"-\" | awk '{print \"ethtool \" $1}' | sh";
   const char  *bond = "for bond in `ls /proc/net/bonding | grep bond`; do echo \"---------- Bonding - $bond ----------\"; echo \"cat /proc/net/bonding/$bond\" | sh ; done";
   const char  *gateway = "route -n | grep ^0.0.0.0 | awk '{print $2}'";
   const char  *dns = "cat /etc/resolv.conf  | grep nameserver";
   const char  *vgdis = "vgs | awk '{print \"vgdisplay \" $1}' |grep -v VG | sh";
   const char  *cron = "for user in `ls /var/spool/cron/`; do echo \"---------- Cron Job - $user ----------\"; echo \"cat /var/spool/cron/$user\" | sh ; done";
   const char  *fibre = "lspci | grep Fibre";
   const char  *nic = "lspci | grep Ethernet";
   const char  *vga = "lspci | grep VGA";
   char  buff[BUFF_SIZE];
   FILE *fp;

    printf("\n");
    printf("LinuxConf for RHEL");
    printf("\n");

   fp = popen( "date", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Exec date : %s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[101m================= Server Information  =================\033[0m\n");
    printf("\n");
    printf("* Hardware Information\n");
    printf("\n");

   fp = popen( "hostname", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Hostname : %s", buff);

   pclose( fp);

   fp = popen( pname, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   fp = popen( serial, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   fp = popen( cpuname, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "CPU Model :%s", buff);

   pclose( fp);

   fp = popen( cpucore, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "CPU Core : %s", buff);

   pclose( fp);

   fp = popen( cpuphy, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Physical CPU NUM : %s", buff);

   pclose( fp);

   fp = popen( cpumhz, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "CPU Speed : %s", buff);

   pclose( fp);


   fp = popen( memtotal, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("* OS Information\n");
    printf("\n");
  
   fp = popen( "cat /etc/redhat-release", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "OS Version : %s", buff);

   pclose( fp);

   fp = popen( kernelv, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Kernel Version : %s", buff);

   pclose( fp);

   fp = popen( kernelr, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Kernel Release : %s", buff);

   pclose( fp);

    printf("\n");
    printf("* Memory Information\n");
    printf("\n");

   fp = popen( "free", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   fp = popen( "vmstat", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[101m================= Network Information  =================\033[0m\n");
    printf("\n");

    printf("* Network Address\n");
    printf("\n");

   fp = popen( ifconfig, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("* Bonding Status\n");
    printf("\n");

   fp = popen( bond, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);


    printf("\n");
    printf("* Link Mode/Link Speed\n");
    printf("\n");

   fp = popen( ethtool, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("* Routing Table\n");
    printf("\n");

   fp = popen( "netstat -rn", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("* Default Gateway\n");
    printf("\n");

   fp = popen( gateway, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "Gateway : %s", buff);

   pclose( fp);

    printf("\n");
    printf("* DNS\n");
    printf("\n");

   fp = popen( dns, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[101m================= Disk Information  =================\033[0m\n");
    printf("\n");

    printf("* Filesystem Information\n");

   fp = popen( "cat /etc/fstab", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");

   fp = popen( "df -h", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
   
   printf("* Volume Group Information\n");

   fp = popen( "vgs", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");

  fp = popen( vgdis, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   printf("* Logical Volume Information\n");

   fp = popen( "lvs", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");

  fp = popen( "lvdisplay", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   printf("* Physical Volume Information\n");

   fp = popen( "pvs", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");

  fp = popen( "pvdisplay", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

   printf("* Fdisk\n");

   fp = popen( "fdisk -l", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[101m================= PCI Card Information  =================\033[0m\n");
    printf("\n");

    printf("* HBA Information\n");

   fp = popen( fibre, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("* Network Interface Information\n");

   fp = popen( nic, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("* Video Card Information\n");

   fp = popen( vga, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[101m================= ETC Information  =================\033[0m\n");
    printf("\n");

    printf("* User List\n");

   fp = popen( "w", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    
    printf("* Cron job List\n");

   fp = popen( cron, "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");

   printf("* Process List - \"ps -ef\"\n");

   fp = popen( "ps -ef", "r");
   if ( NULL == fp)
   {
      perror( "popen() fail");
      return -1;
   }

   while( fgets( buff, BUFF_SIZE, fp) )
      printf( "%s", buff);

   pclose( fp);

    printf("\n");
    printf("\033[103m============================================================ CJ ONS yongho.kwon1@cj.net =========== \033[0m\n");

    return 0;
}

