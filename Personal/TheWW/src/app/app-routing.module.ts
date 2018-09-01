import {ModuleWithProviders} from '@angular/core';
import {Routes, RouterModule} from '@angular/router';
import {GalleryComponent} from './pages/gallery/gallery.component';
import {HomeComponent} from './pages/home/home.component';
import {AboutComponent} from './pages/about/about.component';
import {GalleryViewerComponent} from './pages/gallery-viewer/gallery-viewer.component';


const routes: Routes = [
  {
    path: '',
    component: HomeComponent
  },
  {
    path: 'gallery',
    component: GalleryComponent,
  },
  {
    path: 'gallery/:country',
    component: GalleryComponent,
  },
  {
    path: 'about',
    component: AboutComponent
  }
];

export const MyRoutes: ModuleWithProviders = RouterModule.forRoot(routes);
