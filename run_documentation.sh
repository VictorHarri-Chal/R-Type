echo "Creating documentation..."
echo "-------------------------"
echo " "
echo "1. Creating folder doc/output"
[ -f doc ] && rm -fr doc
mkdir -p doc/output
echo "2. Installing dependencies"
if [ "$os_name" = "Linux" ]; then
  if [ -z "$DEV_SET" ]; then
    if grep ^NAME= /etc/os-release | grep -iq Ubuntu; then
      sudo apt install -y doxygen
      sudo apt install -y texlive-epstopdf
    fi
    elif grep ^NAME= /etc/os-release | grep -iq Fedora; then
      sudo dnf install -y doxygen
      sudo dnf install -y texlive-epstopdf
    fi
fi
echo "3. Generating documentation"
doxygen
echo "4. Launching documentation"
xdg-open doc/output/html/index.html
