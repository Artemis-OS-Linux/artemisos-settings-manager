# Maintainer : Ramon Buldo <ramon@manjaro.org>

pkgbase=artemisos-settings-manager
pkgname=('artemisos-settings-manager' 'artemisos-settings-manager-kcm'
         'artemisos-settings-manager-notifier' 'artemisos-settings-manager-knotifier')
pkgver=2.0.1
#_commit=e085b661c3c97e8aa39a5b49896a88a95d84caf9
pkgrel=1
pkgdesc="ArtemisOS System Settings Tool"
arch=('i686' 'x86_64')
url="https://github.com/Artemis-OS-Linux/artemisos-settings-manager"
license=("GPL")
depends=('icu' 'qt5-base>=5.12.3' 'hwinfo' 'kitemmodels' 'kauth'
         'kcoreaddons' 'ckbcomp' 'xdg-utils')
optdepends=('artemisos-settings-manager-notifier: qt-based'
            'artemisos-settings-manager-knotifier: knotifications-based')
makedepends=('extra-cmake-modules' 'kdoctools' 'qt5-tools' 'knotifications' 
             'kconfigwidgets' 'kcmutils')
conflicts=('kcm-asm')
# source=("asm-$pkgver-$pkgrel.tar.gz::$url/-/archive/$_commit/$pkgname-$_commit.tar.gz")
source=("asm-$pkgver-$pkgrel.tar.gz::https://github.com/Artemis-OS-Linux/artemisos-settings-manager/archive/refs/tags/$pkgver.tar.gz")
sha256sums=('SKIP')
#sha256sums=('2cebe2485563c9bb9445df0ae7644fdcfa6d0ac3167cf0205c5a785f8520f376')

prepare() {
#  mv ${pkgbase}-${_commit} ${pkgbase}-${pkgver}
  cd "$srcdir/${pkgbase}-${pkgver}"
  # patches here
}

build() {
  cd "$srcdir/${pkgbase}-${pkgver}"
  mkdir -p build
  cd build
  cmake ../ \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DLIB_INSTALL_DIR=lib \
    -DKDE_INSTALL_USE_QT_SYS_PATHS=ON \
    -DSYSCONF_INSTALL_DIR=/etc
  CXXFLAGS+="-std=gnu++98" make
}

package_artemisos-settings-manager() {
  cd "$srcdir/${pkgbase}-${pkgver}/build"
  make DESTDIR=${pkgdir} install 
  rm -rf $pkgdir/usr/bin/asm_notifier
  rm -rf $pkgdir/usr/bin/asm_kde_notifier
  rm -rf $pkgdir/usr/lib/qt
  rm -rf $pkgdir/usr/share/kservices5
  rm -rf $pkgdir/usr/share/applications/asm_notifier_settings.desktop
  rm -rf $pkgdir/usr/share/applications/asm_kde_notifier_settings.desktop
  rm -rf $pkgdir/etc/xdg
}

package_artemisos-settings-manager-kcm() {
  pkgdesc="ArtemisOS System Settings Tool (KCM for Plasma 5)"
  depends=('artemisos-settings-manager' 'kcmutils' 'kconfigwidgets')
  replaces=('kcm-asm')
  cd "$srcdir/${pkgbase}-${pkgver}/build"
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc  
  rm -rf $pkgdir/usr/bin
  rm -rf $pkgdir/usr/lib/kauth
  rm -rf $pkgdir/usr/share/{applications,dbus-1,icons,polkit-1}
}

package_artemisos-settings-manager-notifier() {
  pkgdesc="ArtemisOS System Settings Tool (Notifier)"
  depends=('artemisos-settings-manager')
  provides=('artemisos-settings-manager-kde-notifier')
  conflicts=('artemisos-settings-manager-kde-notifier')
  cd "$srcdir/${pkgbase}-${pkgver}/build"
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc/dbus-1
  rm -rf $pkgdir/etc/xdg/autostart/asm_kde_notifier.desktop
  rm -rf $pkgdir/usr/lib/
  rm -rf $pkgdir/usr/share/{kservices5,dbus-1,icons,polkit-1}
  rm -rf $pkgdir/usr/share/applications/manjaro*
  rm -rf $pkgdir/usr/share/applications/asm_kde_notifier_settings.desktop
  rm -rf $pkgdir/usr/bin/manjaro*
  rm -rf $pkgdir/usr/bin/asm_kde_notifier
}

package_artemisos-settings-manager-knotifier() {
  pkgdesc="ArtemisOS System Settings Tool (Notifier for Plasma 5)"
  depends=('artemisos-settings-manager' 'knotifications')
  conflicts=('artemisos-settings-manager-notifier')
  replaces=('artemisos-settings-manager-kde-notifier')
  cd "$srcdir/${pkgbase}-${pkgver}/build"
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc/dbus-1
  rm -rf $pkgdir/etc/xdg/autostart/asm_notifier.desktop
  rm -rf $pkgdir/usr/lib/
  rm -rf $pkgdir/usr/share/{kservices5,dbus-1,icons,polkit-1}
  rm -rf $pkgdir/usr/share/applications/manjaro*
  rm -rf $pkgdir/usr/share/applications/asm_notifier_settings.desktop
  rm -rf $pkgdir/usr/bin/manjaro*
  rm -rf $pkgdir/usr/bin/asm_notifier
} 
