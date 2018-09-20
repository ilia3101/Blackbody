set terminal pngcairo size 2000,1024 font ',18' enhanced
set output "pic_multi_kenngr_ana.png 

#set logscale y 5

#set ylabel "Spectral radiance" \si{W*sr^(-1)*m^(-2)*Hz^(-1)}
set ylabel "Radiance"
set xlabel "Wavelength (nm)"

set grid lt 0 lw 1.2 lc rgb "#111111"

#set ytics 5
#set xtics 5

set xtics add (390)
set xtics add (770)

#set terminal postscript eps color
#set output "plot.eps"
#plot "3000k.txt" "5000k.txt" "8000k.txt" with lines lw 2
#plot "5000k.txt" with lines lw 2
#plot "8000k.txt" with lines lw 2

plot "3000k.txt" title '3000K' with lines lw 2, \
     "4000k.txt" title '4000K' with lines lw 2, \
     "4500k.txt" title '4500K' with lines lw 2, \
     "5000k.txt" title '5000K' with lines lw 2, \
     "5500k.txt" title '5500K' with lines lw 2, \
     "6000k.txt" title '6000K' with lines lw 2
